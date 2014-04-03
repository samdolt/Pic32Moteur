#ifndef Mc32Gest_RS232_H
#define Mc32Gest_RS232_H
/*--------------------------------------------------------*/
/* Mc32Gest_RS232.h
/*--------------------------------------------------------*/
/*	Description :	emission et reception spécialisée
/*			pour TP2B
/*
/*	Auteur 		: 	F. Dominé
/*
/*	Version		:	V1.0
/*	Compilateur	:	XC32 V1.20
//
/*--------------------------------------------------------*/


/*--------------------------------------------------------*/
/* Définition des fonctions prototypes
/*--------------------------------------------------------*/
#include <stdint.h>

#ifndef sint8
    #define sint8 int8_t
#endif

#ifndef uint8
    #define uint8 uint8_t
#endif


#ifndef uint16
    #define uint16 uint16_t
#endif


// prototypes des fonctions
void InitComm(void);
int GetMessage(sint8 *Speed, sint8 *Angle);
void SendMessage(sint8 Speed, sint8 Angle);

#endif
