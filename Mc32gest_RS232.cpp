// Mc32Gest_RS232.C
// Canevas manipulation TP2B RS232 SLO2 2013-2014
// fonction d'émission et de réception des message




#include "GesFifoTh32.h"
#include "Mc32gest_RS232.h"
#include "SK32MX795F512L.h"
#include <plib.h>
#include "Mc32CalCrc16.h"

#define SYS_FREQ (80000000L)    //80 MHz
#define PB_DIV 1
#define PB_FREQ (SYS_FREQ / PB_DIV)


// prototypes des fonctions locale
void ComposeTxMess(sint8 Vitesse, sint8 Angle);



typedef union {
         uint16 val;
         struct {uint8 lsb;
                 uint8 msb;} shl;
} U_manip16;


// Definition pour les messages
#define MESS_SIZE  5
#define STX_code  (0xAA)

// Structure décrivant le message
typedef struct {
   uint8 Start;
   sint8 Speed;
   sint8 Angle;
   U_manip16 Crc16;
} StruMess;


// Struct pour émission des messages
StruMess TxMess;
// Struct pour réception des messages
StruMess RxMess;

volatile uint32_t RemoteSpeed = 0;
volatile int32_t RemoteAngle = 0;
volatile int8_t compt_getmessage = 0;

// Declaration des FIFO pour réception et émission
#define FIFO_RX_SIZE ( (4*5) + 1)  // 4 messages
#define FIFO_TX_SIZE ( (4*5) + 1)  // 4 messages

sint8 fifoRX[FIFO_RX_SIZE];
// Declaration du descripteur du FIFO de réception
S_fifo descrFifoRX;


sint8 fifoTX[FIFO_TX_SIZE];
// Declaration du descripteur du FIFO d'émission
S_fifo descrFifoTX;



// Réponse Interruption de l'UART
// Il est nécessaire de tester si RX ou TX
// L'interruption de réception est supposée se produire au 3/4 du fifo HW
// l'interruption de transmission est supposée avoir lieu lorsque le fifo HW est vide

extern "C"
{
void __ISR(_UART_1_VECTOR, IPL5SOFT) UART1_isr(void)
{
   uint8 ErrFiFoFull = 0;
   uint8 freeSize, TXsize;
   sint8 c;
   uint8 i_cts = 0;
   BOOL  TxPossible;

   UART_LINE_STATUS lineStatus;

    // Toggle LED3 pour indiquer activité
     mPORTAToggleBits(BIT_5);
     
    // Is this an RX interrupt ?
    if ( INTGetFlag(INT_U1RX) && INTGetEnable(INT_U1RX) ) {

        // oui Test si erreur comm
        lineStatus = UARTGetLineStatus(UART1);
          
        if ( (lineStatus & (UART_PARITY_ERROR | UART_FRAMING_ERROR |
                            UART_OVERRUN_ERROR)) == 0) {
             // transfert dans le fifo de tous les caractères recu
             while (UARTReceivedDataIsAvailable(UART1))
             {
                 c = UARTGetDataByte(UART1);
                 PutCharInFifo ( &descrFifoRX, c);
             }
             INTClearFlag(INT_U1RX); // buffer is empty, clear interrupt flag
     
        } else {
             UART1ClearAllErrors();   // Macro C32
        }
  
         freeSize = GetWriteSpace ( &descrFifoRX);
         if (freeSize <= 6 )        // a cause d'un int pour 6 char
         {
            // Demande de ne plus émettre
            RS232_RTS = 1;

            if (freeSize == 0) {
                 ErrFiFoFull = 1;    // pour debugging si probème ctrl flux
            }
        }
    } // end if RX

    // Is this an TX interrupt ?
    if(INTGetFlag(INT_U1TX) && INTGetEnable(INT_U1TX)  ) {

             
         TXsize = GetReadSize (&descrFifoTX);
         // i_cts = input(RS232_CTS);
         // On vérifie 3 conditions :
         //    Si CTS = 0 (autorisation d'émettre)
         //    Si il y a un caratères à émettre
         //    Si le txreg est bien disponible

         i_cts = RS232_CTS;

         TxPossible = UARTTransmitterIsReady(UART1);
         if ( (i_cts == 0) && ( TXsize > 0 ) && TxPossible )  {

             do {
                 GetCharFromFifo(&descrFifoTX, &c);
           
                 UARTSendDataByte(UART1, c);
                 i_cts = RS232_CTS;
                 TXsize = GetReadSize (&descrFifoTX);
                 TxPossible = UARTTransmitterIsReady(UART1);

             } while ( (i_cts == 0) && ( TXsize > 0 ) && TxPossible  );

            // Clear the TX interrupt Flag (Seulement aprés TX)
            INTClearFlag(INT_U1TX);
        } else {
           // disable TX interrupt
           INTEnable(INT_U1TX, INT_DISABLED);
        }
    }
} // UART_isr

}





// Initialisation de la communication sériel
// -----------------------------------------

void InitComm(void)
{
     
   // Initialisation du fifo de réception
   InitFifo ( &descrFifoRX, FIFO_RX_SIZE, fifoRX, 0 );
   // Initialisation du fifo d'émission
   InitFifo ( &descrFifoTX, FIFO_TX_SIZE, fifoTX, 0 );

        
  // Utilisation des fonctions séparées (XC32)
  // =========================================

    UARTConfigure(UART1, (UART_CONFIGURATION) (UART_ENABLE_HIGH_SPEED | UART_ENABLE_PINS_TX_RX_ONLY) );
    // UARTSetFifoMode(UART1, UART_INTERRUPT_ON_TX_BUFFER_EMPTY | UART_INTERRUPT_ON_RX_HALF_FULL  );
    // Remarque HALF_FULL ne fonctionne pas
    // Pour INT RX au 3/4
    UARTSetFifoMode(UART1, (UART_FIFO_MODE) (UART_INTERRUPT_ON_TX_BUFFER_EMPTY | UART_INTERRUPT_ON_RX_3_QUARTER_FULL) );
    // Pour INT RX dés que min 1 char
    // UARTSetFifoMode(UART1, UART_INTERRUPT_ON_TX_BUFFER_EMPTY | UART_INTERRUPT_ON_RX_NOT_EMPTY );
    UARTSetLineControl(UART1, (UART_LINE_CONTROL_MODE) (UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1)) ;
    uint32_t ActualBaudRate = UARTSetDataRate(UART1, PB_FREQ, 57600);
    UARTEnable(UART1, (UART_ENABLE_MODE) UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));
 

   
  // Configuration Int UART1 avec les fonctions séparées
  // ===================================================

  // Configure UART RX Interrupt
  INTEnable( (INT_SOURCE) INT_SOURCE_UART_RX(UART1), INT_ENABLED);
  INTSetVectorPriority((INT_VECTOR) INT_VECTOR_UART(UART1), INT_PRIORITY_LEVEL_5);
  INTSetVectorSubPriority((INT_VECTOR) INT_VECTOR_UART(UART1), INT_SUB_PRIORITY_LEVEL_0);

} // InitComm

 
  
int GetMessage(sint8 *Speed, sint8 *Angle)
{
    int CommStatus;
    uint16_t ValCrc16 = 0xFFFF;  
    
      // Gestion control de flux de la réception
      if(GetWriteSpace ( &descrFifoRX) >= 12) {    // paquet de 6 char
         //calcul CRC
          ValCrc16 = updateCRC16 (ValCrc16, 0xAA);
          ValCrc16 = updateCRC16 (ValCrc16, *Speed);
          ValCrc16 = updateCRC16 (ValCrc16, *Angle);
          
          if (ValCrc16 == RxMess.Crc16.val)
          {
            //   output_low(RS232_RTS);  // autorise émission par l'autre
            RS232_RTS = 0;
            CommStatus = 1;
            compt_getmessage = 0;

            // mise à jour des variable global
            RemoteSpeed = *Speed;
            RemoteAngle = *Angle ;

          }
      }
      compt_getmessage ++;
      if (compt_getmessage >= 10)
      {
          CommStatus = 0;
      }


      return CommStatus;
} // GetCommande


// Fonction d'envoi des message, appel cyclique

void SendMessage(sint8 Speed, sint8 Angle)
{
    sint8 FreeSize;
      
    
      
   // Gestion du control de flux
   // si on a un caractère à envoyer et que CTS = 0
   FreeSize = GetReadSize(&descrFifoTX);
   if ((RS232_CTS == 0) && (FreeSize > 0))
   {
        // Autorise int émission
       INTEnable(INT_U1TX, INT_ENABLED);
   }
}





