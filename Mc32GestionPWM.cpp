// Mc32GestionPWM.c

// C. HUBER    05/04/2014
//
// Fonctions pour la gestion des PWM  TP2
//
// Il s'agit d'un canevas les fonction sont vides
//
//---------------------------------------------------------------------------

#include "Mc32GestionPWM.h"
#include <plib.h>       // peripheral lib
#include "Mc32GestADC.h"

#define SYS_FREQ (80000000L)    //80 MHz
#define PB_DIV 1
// #define PB_FREQ (SYS_FREQ / PB_DIV)
#define PB_FREQ (SYS_FREQ / PB_DIV)

#define VAL_PR2 (25 * (80))


//Timer3
#define PRESCALE_3 64
#define T3_TICK ((1000000.0 * PRESCALE_3)/PB_FREQ) // en us 0.8
 //7 ms => 7'000 us
#define VAL_PR3 (7000 / T3_TICK)


//***************************************************************************
// void GPWM_InitTimerAndOCx (void)
//       Routine effectuant l'initialisation des Timers 2 et 3
//       Ainsi que OC2 et OC3
//       Periode T2 = 1/40 KHz
//       Periode T3 = 7 ms
//       Init OC2 pour PWM
//       Init OC3 pour generation impulsion

void GPWM_InitTimerAndOCx(void)
{
    OpenTimer2(T2_ON | T2_PS_1_1, VAL_PR2);
    OpenOC2(OC_ON | OC_TIMER_MODE16 | OC_TIMER2_SRC | OC_PWM_FAULT_PIN_DISABLE, VAL_PR2/2, VAL_PR2/2);

    OpenTimer3(T3_ON | T3_SOURCE_INT |T3_PS_1_64, VAL_PR3);
    OpenOC3(OC_ON | OC_TIMER_MODE16 | OC_TIMER3_SRC | OC_CONTINUE_PULSE, 2000.0 / T3_TICK , 0);
  
} // end GPWM_InitTimerAndOCx


//***************************************************************************
// void GPWM_DoSettings (void)
//       Routine effectuant le traitement d'acquisition des consignes
//       pour les rapports cyclique des signaux PWM
//

void GPWM_DoSettings(void )
{
   

} // end GPWM_DoSettings

//***************************************************************************
// void GPWM_DoPWMSoftware (void)
// Traitement PWM software
//
void GPWM_DoPWMSoftware(void)
{


} // end GPWM_DoPWMSoftware