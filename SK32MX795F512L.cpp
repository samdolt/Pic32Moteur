/*--------------------------------------------------------*/
/* fichier SK32MX795F512L.c
/*--------------------------------------------------------*/
/*	Description :  Initialisation du starter kit	
/*
/*	Auteur 		: 	F. Dominé
/*  Création	:  15.12.2011
/*  adaptation  :  06.02.2014 C. Huber
/*  Corrections :  20.02.2014 C. Huber  : Suppr action RTCC
/*	Version		:	V1.0
/*	Compilateur	:	C32 V2.01
/*--------------------------------------------------------*/

/*--------------------------------------------------------*/
/* Inclusion des fichies de définition et des librairies
/*--------------------------------------------------------*/
#include "p32mx795f512l.h" // processeur
#include "sk32mx795f512l.h" // définitions des pattes du starter kit

/*--------------------------------------------------------*/
/* Fonction SK32MX795F512L_IO_Default
/*--------------------------------------------------------*/
void SK32MX795F512L_IO_Default(void)
{
	/*--------------------------------------------------------*/
	/* Analogique
	/*--------------------------------------------------------*/
	TRISBbits.TRISB8 = 1; //Analog0 en entrée
	TRISBbits.TRISB1 = 1; //Analog1 en entrée
	TRISBbits.TRISB0 = 1; //Analog2 en entrée
	TRISBbits.TRISB9 = 1; //Analog3 en entrée
	
	/*--------------------------------------------------------*/
	/* Clavier matriciel
	/*--------------------------------------------------------*/
	// A l'initialisation, tout en entrée afin de ne pas avoir de problème
	TRISBbits.TRISB2 = 1; //Colonne1 en entrée
	TRISBbits.TRISB3 = 1; //Colonne2 en entrée
	TRISBbits.TRISB4 = 1; //Colonne3 en entrée
	TRISBbits.TRISB5 = 1; //Colonne4 en entrée
	TRISGbits.TRISG6 = 1; //Ligne1 en entrée
	TRISGbits.TRISG7 = 1; //Ligne2 en entrée
	TRISBbits.TRISB14 = 1; //Ligne3 en entrée
	TRISBbits.TRISB15 = 1; //Ligne4 en entrée

	
	/*--------------------------------------------------------*/
	/* PEC12 -- Touches
	/*--------------------------------------------------------*/
	TRISGbits.TRISG12 = 1; // S_OK & PEC12_PB en entrée
	TRISGbits.TRISG13 = 1; // S_ESC_MENU en entrée
	TRISGbits.TRISG14 = 1; // S_PLUS & PEC12_A en entrée
	TRISGbits.TRISG15 = 1; // S_MINUS & PEC12_B en entrée
	
	/*--------------------------------------------------------*/
	/* I2C
	/*--------------------------------------------------------*/
	TRISAbits.TRISA2 = 0; //I2C_SCL en sortie
	// I2C_SDA Bidirectionnel
	
	/*--------------------------------------------------------*/
	/* SPI -- Chip Select
	/*--------------------------------------------------------*/
	TRISDbits.TRISD3 = 0; //CS_LM70 en sortie
	PORTDbits.RD3 = 1; //CS_LM70 à 1
	TRISDbits.TRISD4 = 0; //CS_DAC en sortie
	PORTDbits.RD4 = 1; //CS_DAC à 1
	TRISDbits.TRISD5 = 0; //CS_SD en sortie
	PORTDbits.RD5 = 1; //CS_SD à 1
	
	/*--------------------------------------------------------*/
	/* Ethernet
	/*--------------------------------------------------------*/
	// Je ne sais pas encore quoi en faire, je mets tout en entrée
	TRISDbits.TRISD6 = 1; //ETH_TX_EN en entrée
	TRISDbits.TRISD7 = 1; //ETH_TX_CLK en entrée
	TRISDbits.TRISD8 = 1; //ETH_MDIO en entrée
	TRISDbits.TRISD11 = 1; //ETH_MDC_EN en entrée
	TRISBbits.TRISB11 = 1; //ETH_RD_ER en entrée
	TRISBbits.TRISB12 = 1; //ETH_D0 en entrée
	TRISBbits.TRISB13 = 1; //ETH_D1 en entrée
	TRISAbits.TRISA14 = 1; //ETH_POWERDOWN_INT en entrée !! CHR
	TRISEbits.TRISE8 = 1; //ETH_AN_EN en entrée
	TRISEbits.TRISE9 = 1; //ETH_AN0 en entrée
	TRISFbits.TRISF0 = 1; //ETH_TX_D1 en entrée
	TRISFbits.TRISF1 = 1; //ETH_TX_D0 en entrée
	TRISGbits.TRISG8 = 1; //ETH_CRS_DV en entrée
	TRISGbits.TRISG8 = 1; //ETH_RST en entrée

	/*----------------------------------------------------*/
	/* SD Card 
	/*----------------------------------------------------*/
	TRISCbits.TRISC3 = 1; //SD_DETECT en entrée

	/*----------------------------------------------------*/
	/* DAC
	/*----------------------------------------------------*/
	TRISDbits.TRISD9 = 0; //DAC_CLEAR en sortie
	PORTDbits.RD9 = 1; //DAC_CLEAR = 1

	/*----------------------------------------------------*/
	/* LEDs
	/*----------------------------------------------------*/
        // Attention modif importante

	LED0_T = 0; //LED_D6  (Led0) en sortie
	LED0_W = 1; //LED_D6  (Led0) = 1
	LED1_T = 0; //LED_D10 (Led1) en sortie
	LED1_W = 1; //LED_D10 (Led1) = 1
	LED2_T = 0; //LED_D7  (Led2) en sortie
	LED2_W = 1; //LED_D7  (Led2) = 1
	LED3_T = 0; //LED_D11 (Led3) en sortie
	LED3_W = 1; //LED_D11 (Led3) = 1
	LED4_T = 0; //LED_D8  (Led4) en sortie
	LED4_W = 1; //LED_D8  (Led4) = 1
	LED5_T = 0; //LED_D12 (Led5) en sortie
	LED5_W = 1; //LED_D12 (Led5) = 1
	LED6_T = 0; //LED_D9  (Led6) en sortie
	LED6_W = 1; //LED_D9  (Led6) = 1
	LED7_T = 0; //LED_D13 (Led7) en sortie
	LED7_W = 1; //LED_D13 (Led7) = 1

	/*--------------------------------------------------------*/
	/* USB
	/*--------------------------------------------------------*/
	TRISFbits.TRISF3 = 1; //USB_DETECT en entrée
	TRISGbits.TRISG2 = 1; //USB_PLUS en entrée par sécurité
	TRISGbits.TRISG3 = 1; //USB_MINUS en entrée par sécurité
	
	/*--------------------------------------------------------*/
	/* RS232
	/*--------------------------------------------------------*/
	TRISFbits.TRISF8 = 0; //RS232_TX en sortie
	PORTFbits.RF8 = 1; //RS232_TX à 1
	TRISFbits.TRISF2 = 1; //RS232_RX en entrée
	TRISDbits.TRISD15 = 0; //RS232_RTS en sortie
	PORTDbits.RD15 = 1; //RS232_RTS à 1
	TRISDbits.TRISD14 = 1; //RS232_CTS en entrée
	
	/*--------------------------------------------------------*/
	/* LCD
	/*--------------------------------------------------------*/
	// On met d'abord toutes les pattes du LCD à 1 sauf le backlight
        LCD_RS_W = 1;
        LCD_RW_W = 1;
        LCD_E_W = 1;
        LCD_BL_W = 0;
        LCD_DB4_W = 1;
        LCD_DB5_W = 1;
        LCD_DB6_W = 1;
        LCD_DB7_W = 1;
        // Puis on configure toutes les pattes en sortie, lorsqu'on aura besoin, on modifiera
        // ce qu'il faut en entrée
	LCD_RS_T = 0; //LCD_RS en sortie
	LCD_RW_T = 0; //LCD_RW en sortie
	LCD_E_T = 0; //LCD_E en sortie
	LCD_BL_T = 0; //LCD_BL en sortie
	LCD_DB4_T = 0; //LCD_DB4 en sortie
	LCD_DB5_T = 0; //LCD_DB5 en sortie
	LCD_DB6_T = 0; //LCD_DB6 en sortie
	LCD_DB7_T = 0; //LCD_DB7 en sortie
	
	/*--------------------------------------------------------*/
	/* Pont en H
	/*--------------------------------------------------------*/
	// Par sécurité, on met tout en entrée au départ 
	TRISCbits.TRISC13 = 1; //STBY_HBRIDGE en entrée
	TRISDbits.TRISD12 = 1; //AIN1_HBRIDGE en entrée
	TRISDbits.TRISD13 = 1; //AIN2_HBRIDGE en entrée
	TRISDbits.TRISD1 = 1; //PWMA_HBRIDGE en entrée
	TRISCbits.TRISC1 = 1; //BIN1_HBRIDGE en entrée
	TRISCbits.TRISC2 = 1; //BIN2_HBRIDGE en entrée
	TRISDbits.TRISD2 = 1; //PWMB_HBRIDGE en entrée
	
	/*--------------------------------------------------------*/
	/* XBee
	/*--------------------------------------------------------*/
	TRISFbits.TRISF5 = 0; //XBEE_TX en sortie
	PORTFbits.RF5 = 1; //XBEE_TX = 1
	TRISFbits.TRISF4 = 1; //XBEE_RX en entrée 
	TRISFbits.TRISF13 = 0; //XBEE_RTS en sortie
	PORTFbits.RF13 = 1; //XBEE_RTS = 1
	TRISFbits.TRISF12 = 1; //XBEE_CTS en entrée
	TRISGbits.TRISG0 = 1; //XBEE_ON_SLEEP en entrée
	TRISGbits.TRISG1 = 0; //XBEE_RESET en sortie
	PORTGbits.RG1 = 1; //XBEE_RESET = 1

	/*--------------------------------------------------------*/
	/* RTCC
	/*--------------------------------------------------------*/
        // Supprimé devenu LED7
	// TRISBbits.TRISB10 = 1; //RTCC_MFP en entrée
}
