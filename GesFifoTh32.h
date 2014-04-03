#ifndef GesFifoTh32_H
#define GesFifoTh32_H
/*--------------------------------------------------------*/
/*							Mc32Delays.h
/*--------------------------------------------------------*/
/*	Description :	Cr�ation ent�te pour utilisation 
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

// structure d�crivant un FIFO
typedef struct fifo {
   sint8 fifoSize;   // taille du fifo
   sint8 *pDebFifo;   // pointeur sur d�but du fifo
   sint8 *pFinFifo;   // pointeur sur fin du fifo
   sint8 *pWrite;      // pointeur d'�criture
   sint8 *pRead;      // pointeur de lecture
} S_fifo;

/*--------------------------------------------------------*/
/* D�finition des fonctions de gestion du fifo            */
/*--------------------------------------------------------*/

/*---------------*/
/* InitFifo      */
/*===============*/

// Initialisation du descripteur de FIFO
void InitFifo ( S_fifo *pDescrFifo, sint8 FifoSize, sint8 *pDebFifo, sint8 InitVal );

/*---------------*/
/* GetWriteSpace */
/*===============*/

// Retourne la place disponible en �criture

sint8 GetWriteSpace ( S_fifo *pDescrFifo);

/*-------------*/
/* GetReadSize */
/*=============*/

// Retourne le nombre de caract�res � lire

sint8 GetReadSize ( S_fifo *pDescrFifo);

/*---------------*/
/* PutCharInFifo */
/*===============*/

// D�pose un caract�re dans le FIFO
// Retourne 0 si OK, 1 si FIFO full

uint8 PutCharInFifo ( S_fifo *pDescrFifo, sint8 charToPut );

/*-----------------*/
/* GetCharFromFifo */
/*=================*/

// Obtient (lecture) un caract�re du fifo
// retourne 0 si OK, 1 si empty
// le caract�re lu est retourn� par r�ference

uint8 GetCharFromFifo ( S_fifo *pDescrFifo, sint8 *carLu );

#endif
