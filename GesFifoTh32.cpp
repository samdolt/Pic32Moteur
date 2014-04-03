// ETML Ecole Technique
// Fichier GesFifoTh.c

// Exemple gestion d'un fifo de caract�re, utilisation de pointeur et
// d'un descripteur de fifo

// Cr�ation : Christian HUBER      06/05/2003

#include "GesFifoTh32.h"


// prototypes des fonctions de gestion du fifo
uint8 putChar ( S_fifo *pDescrFifo, sint8 charToPut );
uint8 getChar ( S_fifo *pDescrFifo, sint8 *carLu );


/*---------------*/
/* InitFifo      */
/*===============*/

// Initialisation du descripteur de FIFO
void InitFifo ( S_fifo *pDescrFifo, sint8 FifoSize, sint8 *pDebFifo, sint8 InitVal )
{
   sint8 i;
   sint8 *pFif;
   pDescrFifo->fifoSize =   FifoSize;
   pDescrFifo->pDebFifo =   pDebFifo; // d�but du fifo
   // fin du fifo
   pDescrFifo->pFinFifo =   pDebFifo + (FifoSize - 1);
   pDescrFifo->pWrite   =   pDebFifo;  // d�but du fifo
   pDescrFifo->pRead     =   pDebFifo;  // d�but du fifo
   pFif = pDebFifo;
   for (i=0; i < FifoSize; i++) {
      *pFif  = InitVal;
      pFif++;
   }
} /* InitFifo */


/*---------------*/
/* GetWriteSpace */
/*===============*/

// Retourne la place disponible en �criture

sint8 GetWriteSpace ( S_fifo *pDescrFifo)
{
   sint8 writeSize;

   // D�termine le nb de car.que l'on peut d�poser
   writeSize = pDescrFifo->pRead - pDescrFifo->pWrite -1;
   if (writeSize < 0) {
      writeSize = writeSize + pDescrFifo->fifoSize;
    }
   return (writeSize);
} /* GetWriteSpace */


/*-------------*/
/* GetReadSize */
/*=============*/

// Retourne le nombre de caract�res � lire

sint8 GetReadSize ( S_fifo *pDescrFifo)
{
   sint8 readSize;

   readSize = pDescrFifo->pWrite - pDescrFifo->pRead;
   if (readSize < 0) {
       readSize = readSize +  pDescrFifo->fifoSize;
   }

   return (readSize);
} /* GetReadSize */

/*---------------*/
/* PutCharInFifo */
/*===============*/

// D�pose un caract�re dans le FIFO
// Retourne 0 si OK, 1 si FIFO full

uint8 PutCharInFifo ( S_fifo *pDescrFifo, sint8 charToPut )
{
   uint8 writeStatus;

   // test si fifo est FULL
   if (GetWriteSpace(pDescrFifo) == 0) {
      writeStatus = 1; // fifo FULL
   }
   else {
      // �crit le caract�re dans le FIFO
      *(pDescrFifo->pWrite) = charToPut;

      // incr�ment le pointeur d'�criture
      pDescrFifo->pWrite++;
      // gestion du rebouclement
      if (pDescrFifo->pWrite > pDescrFifo->pFinFifo) {
          pDescrFifo->pWrite = pDescrFifo->pDebFifo;
      }

      writeStatus = 0; // OK
   }
   return (writeStatus);
} // PutCharInFifo 


/*-----------------*/
/* GetCharFromFifo */
/*=================*/

// Obtient (lecture) un caract�re du fifo 
// retourne 0 si OK, 1 si empty
// le caract�re lu est retourn� par r�ference

uint8 GetCharFromFifo ( S_fifo *pDescrFifo, sint8 *carLu )
{
   sint8 readSize;
   uint8 readStatus;

   // d�termine le nb de car. que l'on peut lire
   readSize = GetReadSize(pDescrFifo);

   // test si fifo est vide
   if (readSize == 0) {
      readStatus = 1; // fifo EMPTY
      *carLu = 0;     // carLu = NULL
   }
   else {
      // lis le caract�re dans le FIFO
      *carLu = *(pDescrFifo->pRead);

      // incr�ment du pointeur de lecture
      pDescrFifo->pRead++;
      // gestion du rebouclement
      if (pDescrFifo->pRead > pDescrFifo->pFinFifo) {
          pDescrFifo->pRead = pDescrFifo->pDebFifo;
      }
      readStatus = 0; // OK
   }
   return (readStatus);
} // GetCharFromFifo 


