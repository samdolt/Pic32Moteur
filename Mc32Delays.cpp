/*--------------------------------------------------------*/
/*							Mc32Delays.c
/*--------------------------------------------------------*/
/*	Description :	Fonctions de delay afin 
/*					de pouvoir utiliser la même syntaxe 
/*					que sous CCS.
/*
/*	Auteur 		: 	F. Dominé
/*					
/*	Version		:	V1.0
/*	Compilateur	:	C32 V2.01
//
// Revu / modifié: 
/*--------------------------------------------------------*/

/*--------------------------------------------------------*/
/* Inclusion des fichiers de définition et des librairies
/*--------------------------------------------------------*/
// Tous les fichiers .h nécessaires à la compilation de ce fichier
// doivent être mentionnés ici.
// Il y a un mécanisme qui empêche qu'un fichier .h ne soit traité
// 2 fois, il s'agit du test en début de fichier.
// Si le compilateur a déjà traité le fichier, il ne le retraite
// pas grâce au test effectué au début du fichier.
#include "Mc32Delays.h"

/*--------------------------------------------------------*/
/* Fonction delay500ns
/*--------------------------------------------------------*/
void delay500ns(void)
{
  // Il a fallu touiller un peu pour arriver à 500ns
	unsigned int cptcycles;
	  for (cptcycles=0; cptcycles<2; cptcycles++) {
		delay_cycle();
      }
}
/*--------------------------------------------------------*/
/* Fonction delay_us
/*--------------------------------------------------------*/
void delay_us(unsigned int us)
{
  // Il a fallu touiller un peu pour arriver à la us
	unsigned int i,j,cptcycles;
	for(i=1;i<=us;i++){
	  for (cptcycles=0; cptcycles<3; cptcycles++) {
		delay_cycle();
      }
      if (i==us) {
        delay_cycle();
        delay_cycle();
        delay_cycle();
        delay_cycle();
      }
      else { //compensation des call, return, sauvegardes et restitutions
        j=0;
        j++;
        j++;
        j++;
        j++;
        j++;
        j++;
        delay_cycle();
        delay_cycle();
        delay_cycle();
     }
  }
}
/*--------------------------------------------------------*/
/* Fonction delay_ms
/*--------------------------------------------------------*/
void delay_ms(unsigned int ms)
{
	
	unsigned int i;

	for(i=1;i<=ms;i++)
	{
		// 1ms = 1000us
		delay_us(1000); 	
	}
}
