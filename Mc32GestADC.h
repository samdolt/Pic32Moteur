#ifndef __MC32GESTADC_H
#define __MC32GESTADC_H
/*--------------------------------------------------------*/
/*	Mc32GestADC.h
/*--------------------------------------------------------*/
/*	Description :	Gestion du convertisseur A/D
/*
/*	Auteur 		: 	C. Huber
/*	Version		:	V1.1   6.03.2014
/*	Compilateur	:	XC32 V1.31
//
/*--------------------------------------------------------*/

#include "type_def32.h"


/*--------------------------------------------------------*/
/* Fonction InitADC                                       */
/*--------------------------------------------------------*/
void InitADC(void);

/*--------------------------------------------------------*/
/* Fonction MyReadADC                                       */
/*--------------------------------------------------------*/
uint16 MyReadADC(uint8 NoCh);

#endif