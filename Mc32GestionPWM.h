#ifndef MC32GESTIONPWM_H
#define MC32GESTIONPWM_H

// Mc32GestionPWM.h

// C. HUBER    05/04/2014
//
// Fonctions pour la gestion des PWM  TP2
//
//---------------------------------------------------------------------------

#include "Type_Def32.h"

//***************************************************************************
// void GPWM_InitTimerAndOCx (void)
//       Routine effectuant l'initialisation des Timers 2 et 3
//       Ainsi que OC2 et OC3


void GPWM_InitTimerAndOCx(void);

//***************************************************************************
// void GPWM_DoSettings (void)
//       Routine effectuant le traitement d'acquisition des consignes
//       pour les rapports cyclique des signaux PWM
//

void GPWM_DoSettings(void );

//***************************************************************************
// void GPWM_DoPWMSoftware (void)
// Traitement PWM software
//
void GPWM_DoPWMSoftware(void);

#endif