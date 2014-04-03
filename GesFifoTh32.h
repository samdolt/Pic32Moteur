#ifndef GesFifoTh32_H
#define GesFifoTh32_H
/*--------------------------------------------------------*/
/*							Mc32Delays.h
/*--------------------------------------------------------*/
/*	Description :	Création entête pour utilisation 
/*			de GesFifoTh32 
/*
/*	Auteur 		: 	C. Huber
/*
/*	Version		:	V1.0
/*	Compilateur	:	XC32 V1.20
//
/*--------------------------------------------------------*/

#include <stdint.h>

#ifndef sint8
    #define sint8 int8_t
#endif

#ifndef uint8
    #define uint8 uint8_t
#endif

// structure décrivant un FIFO
typedef struct fifo {
   sint8 fifoSize;   // taille du fifo
   sint8 *pDebFifo;   // pointeur sur début du fifo
   sint8 *pFinFifo;   // pointeur sur fin du fifo
   sint8 *pWrite;      // pointeur d'écriture
   sint8 *pRead;      // pointeur de lecture
} S_fifo;

/*--------------------------------------------------------*/
/* Définition des fonctions de gestion du fifo            */
/*--------------------------------------------------------*/

/*---------------*/
/* InitFifo      */
/*===============*/

// Initialisation du descripteur de FIFO
void InitFifo ( S_fifo *pDescrFifo, sint8 FifoSize, sint8 *pDebFifo, sint8 InitVal );

/*---------------*/
/* GetWriteSpace */
/*===============*/

// Retourne la place disponible en écriture

sint8 GetWriteSpace ( S_fifo *pDescrFifo);

/*-------------*/
/* GetReadSize */
/*=============*/

// Retourne le nombre de caractères à lire

sint8 GetReadSize ( S_fifo *pDescrFifo);

/*---------------*/
/* PutCharInFifo */
/*===============*/

// Dépose un caractère dans le FIFO
// Retourne 0 si OK, 1 si FIFO full

uint8 PutCharInFifo ( S_fifo *pDescrFifo, sint8 charToPut );

/*-----------------*/
/* GetCharFromFifo */
/*=================*/

// Obtient (lecture) un caractère du fifo
// retourne 0 si OK, 1 si empty
// le caractère lu est retourné par réference

uint8 GetCharFromFifo ( S_fifo *pDescrFifo, sint8 *carLu );

#endif
