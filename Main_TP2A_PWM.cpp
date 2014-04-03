/*--------------------------------------------------------*/
// Fichier 		Main_TP2A_PWM
/*--------------------------------------------------------*/
//	Description : 	Canevas TP2A_PWM
//
//	Auteur 		: 	C. Huber
//      Création	: 	05.03.2014

#include <GenericTypeDefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <tgmath.h>

#include "SK32MX795F512L.h"
#include "Mc32Delays.h"
#include "TextDisplay.h"
#include "Mc32GestionPWM.h"
#include "Mc32GestADC.h"

//=====================================----------------------------------------
// Fuses configuration
//=====================================----------------------------------------
// Set configuration fuses (but only once)

// Set clock configuration
// Input clock = HS 20MHz
#pragma config POSCMOD = HS // Primary Oscillator mode = HS
#pragma config FSOSCEN = OFF // Secondary Oscillator Disable
#pragma config IESO = OFF // Internal External Switch Over bit Disable
#pragma config FNOSC = PRIPLL // Primary oscillator (XT, HS, EC) w/ PLL
#pragma config OSCIOFNC = OFF // Disabled output on clko pin
#pragma config FCKSM = CSDCMD // Clock Switching Disabled, Clock Monitoring Disabled

//Set system PLL configuration (Quartz 8 MHz)
// #pragma FPLLIDIV = DIV_5 // Divide by 5 clock for input to pll ->4MHz
#pragma config FPLLIDIV = DIV_2 // Divide by 2 clock for input to pll ->4MHz
#pragma config FPLLMUL = MUL_20 // Multiply by 20 -> pll output = 80MHz
#pragma config FPLLODIV = DIV_1 // System clock = pll Divide by 1 = 80MHz

// Set peripheral clk div
#pragma config FPBDIV = DIV_8 // Divide by 8

// Set power up timer
#pragma PUT = ON

// set USB
#pragma config FVBUSONIO = OFF // VBUS_ON pin is controlled by the Port Function
#pragma config FUSBIDIO = OFF // USBID pin is controlled by the Port Function

// Set CAN
#pragma config FCANIO = ON // Default CAN IO Pins

// Set Ethernet
#pragma config FETHIO = ON // Default Ethernet IO Pins
#pragma config FMIIEN = ON // MII enabled

// set watchdog
#pragma  config FWDTEN = OFF // Disabled

// Set code protect
#pragma config CP = OFF // Disabled

// Set boot flash code protect
#pragma config BWP = OFF // Disabled

// Set ICD3 channel
#pragma config ICESEL = ICS_PGx2 // ICE pins are shared with PGC2, PGD2

// Set debug bit
#pragma config DEBUG = ON // Enabled

//=====================================----------------------------------------
// définitions des constantes et des variables
//=====================================----------------------------------------
int cpt;
char stringaff[20] = {"Test Int & Timer1"};
int ChenillardPhase = 0;
int compteurMain;
uint8_t Compt_4ms;



//=====================================----------------------------------------
// prototypes (nécessaires si des fonctions sont appelées avant d'être définies,
//     par exemple pour les interruptions)
//=====================================----------------------------------------


//=====================================----------------------------------------
// définitions et mise en place des fonctions d'interruptions
// les fonctions d'interruptions peuvent être définies n'importe où dans le code,
// mais généralement elles sont définies au début de la partie programme
//=====================================----------------------------------------


//=====================================----------------------------------------
// définitions pour les Timers
//=====================================----------------------------------------

#define SYS_FREQ (80000000L)    //80 MHz
#define PB_DIV 1
// #define PB_FREQ (SYS_FREQ / PB_DIV)
#define PB_FREQ (SYS_FREQ / PB_DIV)

//Timer1
#define PRESCALE 256
#define T1_TICK ((1000000.0 * PRESCALE)/PB_FREQ) // en us
// 25 ms => 25'000 us
#define VAL_PR1 (25000 / T1_TICK)

//Timer3
#define PRESCALE_3 64
#define T3_TICK ((1000000.0 * PRESCALE_3)/PB_FREQ) // en us
 //7 ms => 7'000 us
#define VAL_PR3 (7000 / T3_TICK)

//Timer4
#define PRESCALE_4 256
#define T4_TICK ((1000000.0 * PRESCALE_4)/PB_FREQ) // en us
// 40 us
#define VAL_PR4 (40.0 / T4_TICK)


volatile int32_t line2 = 0;
volatile uint32_t line3 = 0;
volatile int32_t line4 = 0;
volatile uint16_t PulseStopOC3 = 0;

//=====================================----------------------------------------
// fonction main
//=====================================----------------------------------------
int main (void){
  // disable JTAG port to free RA0, RA1, RA4 et RA5
  mJTAGPortEnable(0);

  // memory wait states fine tuning
  // TO BE CHECKED
  //SYSTEMConfigPerformance(SYS_FREQ);
  int Pb_freq = SYSTEMConfigPerformance(SYS_FREQ);
  // Etablit PB_CLOCK à 4 MHz
   
  // Default SK32MX775F512L i/os config and values
  SK32MX795F512L_IO_Default();  

  // Configuration Timer1 cycle 25 ms
  // Internal clock, Prescaler 256
  OpenTimer1(T1_ON | T1_SOURCE_INT | T1_PS_1_256, VAL_PR1);
  // Set up the timer interrupt with a priority of 4
  ConfigIntTimer1(T1_INT_ON | T1_INT_PRIOR_4);



 // Configuration Timer4 cycle 40 us
 // Internal clock, Prescaler 1

  OpenTimer4(T4_ON | T4_SOURCE_INT | T4_PS_1_256, VAL_PR4);

  // Set up the timer4 interrupt with a priority of 4 (provisoir)
  ConfigIntTimer4(T4_INT_ON | T4_INT_PRIOR_6);

  // Initialisation timer et OCx pour PWM
  GPWM_InitTimerAndOCx();

  // Init AD
  InitADC();
  
  // lcd init

  TextDisplay lcd = TextDisplay("E0", "E1", "E2", "E3", "E4", "E5", "E6", "E7");


  lcd << "Local Settings" << endl;
  lcd << "TP2A PWM 2013-2014 "  << endl;
  lcd << "Samuel Dolt" << endl;
  lcd << "France Maillard" << endl;

  delay_ms(3000);
  lcd.clear();
  // enable multi-vector interrupts
  INTEnableSystemMultiVectoredInt();

  while(1){
    // Ne rien faire (juste un comptage)
    compteurMain++;

    lcd.set_cursor(2,1);

    lcd << "Vsignee :" << line2 << "    " << endl;
     lcd << "Vnon_signee :" << line3 << "    "  << endl;

    lcd << "Angle :" << line4 << "    " << endl;

    delay_ms(100);
  }
  return 0;
}  // End main


extern "C"
{
    // Réponse à l'interruption du Timer1 (cycle de 25 ms)
    void __ISR(_TIMER_1_VECTOR, IPL4SOFT) Timer1Handler(void)
    {
        uint16_t resultat_ad0, resultat_ad1;
        uint8_t ValDegre;

        // Marqueur activité
        LED0_W = 1;
        // clear the interrupt flag
        mT1ClearIntFlag();

        // Lecture de l'ADC sur le canal 0
        resultat_ad0 = MyReadADC(0);

        // Transformation du resultat en % (ADC 10 Bit)
        //line3 = 99* (resultat_ad0 / 1023.0);
        line2 = (198* (resultat_ad0 / 1023.0)) - 99;
        line3 = abs(line2);

        // Calcul valeur du duty cycle
        SetDCOC2PWM(abs(line2) * ((25 * 80) / 100));

        STBY_HBRIDGE = 1;
        if (line2 < 0)
        {
            AIN1_HBRIDGE = 1; // RD12
            AIN2_HBRIDGE = 0; // RD13
        }
        else
        {
            AIN2_HBRIDGE = 1;
            AIN1_HBRIDGE = 0;
        }
        
        
        // Execute le traitement complet
        GPWM_DoSettings();
        //traitement AD canal 1
            //lecture de l'AD canal 1
            resultat_ad1 = MyReadADC(1);

            //Calcul de 0 à 180
            ValDegre = (resultat_ad1 / 1023.0) * 180;

            //Determiner la pulse_stop pour OC3
           SetPulseOC3((7000-(ValDegre*10+600))/T3_TICK, 0);

            //Transformation de 0 à 180 en -90 à 90
            line4 = ValDegre - 90;
        
        // Marqueur activité
        LED0_W = 0;
    } // End T1 ISR

    // Réponse à l'interruption du Timer4 (cycle 40 us)
    void __ISR(_TIMER_4_VECTOR, IPL6SOFT) Timer4Handler(void)
    {
        // Marqueur activité
        LED1_W = 1;
         // clear the interrupt flag
        mT4ClearIntFlag();

        // Traitement PWM software
        GPWM_DoPWMSoftware();
        Compt_4ms ++;
        if (Compt_4ms >= 99)
        {
            Compt_4ms = 0;
            LED2_W = 1;
        }
        else if (Compt_4ms == (uint8_t) line3)
        {
            LED2_W = 0;
        }



        // Marqueur activité
        LED1_W = 0;
    }
}