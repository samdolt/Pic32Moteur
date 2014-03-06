/*--------------------------------------------------------*/
/*							Mc32Delays.c
/*--------------------------------------------------------*/
/*	Description :	Fonctions de delay afin 
/*					de pouvoir utiliser la m�me syntaxe 
/*					que sous CCS.
/*
/*	Auteur 		: 	F. Domin�
/*					
/*	Version		:	V1.0
/*	Compilateur	:	C32 V2.01
//
// Revu / modifi�: 
/*--------------------------------------------------------*/

/*--------------------------------------------------------*/
/* Inclusion des fichiers de d�finition et des librairies
/*--------------------------------------------------------*/
// Tous les fichiers .h n�cessaires � la compilation de ce fichier
// doivent �tre mentionn�s ici.
// Il y a un m�canisme qui emp�che qu'un fichier .h ne soit trait�
// 2 fois, il s'agit du test en d�but de fichier.
// Si le compilateur a d�j� trait� le fichier, il ne le retraite
// pas gr�ce au test effectu� au d�but du fichier.
#include "Mc32Delays.h"

/*--------------------------------------------------------*/
/* Fonction delay500ns
/*--------------------------------------------------------*/
void delay500ns(void)
{
  // Il a fallu touiller un peu pour arriver � 500ns
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
  // Il a fallu touiller un peu pour arriver � la us
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
