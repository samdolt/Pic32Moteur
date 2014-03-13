/*--------------------------------------------------------*/
/* Mc32GestADC.c
/*--------------------------------------------------------*/
/*	Description :	Fonctions pour gestion ADC 10 bits
/*                      Mecanisme buffer alterné
/*	Auteur 		: 	C. HUBER
/*					
/*	Version		:	V1.1  06.03.2014
/*	Compilateur	:	XC32 V1.3
//
/*--------------------------------------------------------*/


#include "Mc32GestADC.h"
#include <plib.h>

// Define setup parameters for OpenADC10 function
// Turn module on | Ouput in integer format | Trigger mode auto | Enable autosample
#define config1     ADC_FORMAT_INTG | ADC_CLK_AUTO | ADC_AUTO_SAMPLING_ON
// ADC ref external | Disable offset test | Disable scan mode | Perform 2 samples | Use dual buffers | Use alternate mode
#define config2     ADC_VREF_AVDD_AVSS | ADC_OFFSET_CAL_DISABLE | ADC_SCAN_OFF | ADC_SAMPLES_PER_INT_2 | ADC_ALT_BUF_ON | ADC_ALT_INPUT_ON
// Use ADC internal clock | Set sample time
#define config3     ADC_CONV_CLK_INTERNAL_RC | ADC_SAMPLE_TIME_15
#define configport  ENABLE_AN0_ANA | ENABLE_AN1_ANA
// Do not assign channels to scan
#define configscan  SKIP_SCAN_ALL


/*--------------------------------------------------------*/
/* Fonction InitADC
/*--------------------------------------------------------*/
void InitADC(void)
{
    // Init des entrées analogiques correspondant aux pot
    // AN8 et AN9 PortB 8 et 9
    PORTSetPinsAnalogIn(IOPORT_B, BIT_0 | BIT_1);
    CloseADC10();
    // Configure to sample AN8 & AN9
    // Use ground as neg ref for A | use AN8 for input A | use ground as neg ref for A | use AN9 for input B
    SetChanADC10( ADC_CH0_NEG_SAMPLEA_NVREF | ADC_CH0_POS_SAMPLEA_AN0 |  ADC_CH0_NEG_SAMPLEB_NVREF | ADC_CH0_POS_SAMPLEB_AN1);
   
    OpenADC10( config1, config2, config3, configport, configscan );

    EnableADC10();
 }

/*--------------------------------------------------------*/
/* Fonction MyReadADC
/*--------------------------------------------------------*/

// NoCh 0 ou 1
uint16_t MyReadADC(uint8_t NoCh)
{
    uint16_t result;
    unsigned int offset;	// Buffer offset to point to the base of the idle buffer

    ConvertADC10();
    while(BusyADC10());

      // Determine which buffer is idle and create an offset
      offset = 8 * ((~ReadActiveBufferADC10() & 0x01));

        // Lecture résultat de la conversion  "from the idle buffer"
      if (NoCh == 0)  {
          result = ReadADC10(offset);
      }else {
           result = ReadADC10(offset+1);
      }
   return result;
}
