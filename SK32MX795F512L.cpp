/*--------------------------------------------------------*/
/* fichier SK32MX795F512L.c
/*--------------------------------------------------------*/
/*	Description :  Initialisation du starter kit	
/*
/*	Auteur 		: 	F. Domin�
/*  Cr�ation	:  15.12.2011
/*  adaptation  :  06.02.2014 C. Huber
/*  Corrections :  20.02.2014 C. Huber  : Suppr action RTCC
/*	Version		:	V1.0
/*	Compilateur	:	C32 V2.01
/*--------------------------------------------------------*/

/*--------------------------------------------------------*/
/* Inclusion des fichies de d�finition et des librairies
/*--------------------------------------------------------*/
#include "p32xxxx.h" // processeur
#include "sk32mx795f512l.h" // d�finitions des pattes du starter kit

/*--------------------------------------------------------*/
/* Fonction SK32MX795F512L_IO_Default
/*--------------------------------------------------------*/
void SK32MX795F512L_IO_Default(void)
{
	/*--------------------------------------------------------*/
	/* Analogique
	/*--------------------------------------------------------*/
	TRISBbits.TRISB8 = 1; //Analog0 en entr�e
	TRISBbits.TRISB1 = 1; //Analog1 en entr�e
	TRISBbits.TRISB0 = 1; //Analog2 en entr�e
	TRISBbits.TRISB9 = 1; //Analog3 en entr�e
	
	/*--------------------------------------------------------*/
	/* Clavier matriciel
	/*--------------------------------------------------------*/
	// A l'initialisation, tout en entr�e afin de ne pas avoir de probl�me
	TRISBbits.TRISB2 = 1; //Colonne1 en entr�e
	TRISBbits.TRISB3 = 1; //Colonne2 en entr�e
	TRISBbits.TRISB4 = 1; //Colonne3 en entr�e
	TRISBbits.TRISB5 = 1; //Colonne4 en entr�e
	TRISGbits.TRISG6 = 1; //Ligne1 en entr�e
	TRISGbits.TRISG7 = 1; //Ligne2 en entr�e
	TRISBbits.TRISB14 = 1; //Ligne3 en entr�e
	TRISBbits.TRISB15 = 1; //Ligne4 en entr�e

	
	/*--------------------------------------------------------*/
	/* PEC12 -- Touches
	/*--------------------------------------------------------*/
	TRISGbits.TRISG12 = 1; // S_OK & PEC12_PB en entr�e
	TRISGbits.TRISG13 = 1; // S_ESC_MENU en entr�e
	TRISGbits.TRISG14 = 1; // S_PLUS & PEC12_A en entr�e
	TRISGbits.TRISG15 = 1; // S_MINUS & PEC12_B en entr�e
	
	/*--------------------------------------------------------*/
	/* I2C
	/*--------------------------------------------------------*/
	TRISAbits.TRISA2 = 0; //I2C_SCL en sortie
	// I2C_SDA Bidirectionnel
	
	/*--------------------------------------------------------*/
	/* SPI -- Chip Select
	/*--------------------------------------------------------*/
	TRISDbits.TRISD3 = 0; //CS_LM70 en sortie
	PORTDbits.RD3 = 1; //CS_LM70 � 1
	TRISDbits.TRISD4 = 0; //CS_DAC en sortie
	PORTDbits.RD4 = 1; //CS_DAC � 1
	TRISDbits.TRISD5 = 0; //CS_SD en sortie
	PORTDbits.RD5 = 1; //CS_SD � 1
	
	/*--------------------------------------------------------*/
	/* Ethernet
	/*--------------------------------------------------------*/
	// Je ne sais pas encore quoi en faire, je mets tout en entr�e
	TRISDbits.TRISD6 = 1; //ETH_TX_EN en entr�e
	TRISDbits.TRISD7 = 1; //ETH_TX_CLK en entr�e
	TRISDbits.TRISD8 = 1; //ETH_MDIO en entr�e
	TRISDbits.TRISD11 = 1; //ETH_MDC_EN en entr�e
	TRISBbits.TRISB11 = 1; //ETH_RD_ER en entr�e
	TRISBbits.TRISB12 = 1; //ETH_D0 en entr�e
	TRISBbits.TRISB13 = 1; //ETH_D1 en entr�e
	TRISAbits.TRISA14 = 1; //ETH_POWERDOWN_INT en entr�e !! CHR
	TRISEbits.TRISE8 = 1; //ETH_AN_EN en entr�e
	TRISEbits.TRISE9 = 1; //ETH_AN0 en entr�e
	TRISFbits.TRISF0 = 1; //ETH_TX_D1 en entr�e
	TRISFbits.TRISF1 = 1; //ETH_TX_D0 en entr�e
	TRISGbits.TRISG8 = 1; //ETH_CRS_DV en entr�e
	TRISGbits.TRISG8 = 1; //ETH_RST en entr�e

	/*----------------------------------------------------*/
	/* SD Card 
	/*----------------------------------------------------*/
	TRISCbits.TRISC3 = 1; //SD_DETECT en entr�e

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
	TRISFbits.TRISF3 = 1; //USB_DETECT en entr�e
	TRISGbits.TRISG2 = 1; //USB_PLUS en entr�e par s�curit�
	TRISGbits.TRISG3 = 1; //USB_MINUS en entr�e par s�curit�
	
	/*--------------------------------------------------------*/
	/* RS232
	/*--------------------------------------------------------*/
	TRISFbits.TRISF8 = 0; //RS232_TX en sortie
	PORTFbits.RF8 = 1; //RS232_TX � 1
	TRISFbits.TRISF2 = 1; //RS232_RX en entr�e
	TRISDbits.TRISD15 = 0; //RS232_RTS en sortie
	PORTDbits.RD15 = 1; //RS232_RTS � 1
	TRISDbits.TRISD14 = 1; //RS232_CTS en entr�e
	
	/*--------------------------------------------------------*/
	/* LCD
	/*--------------------------------------------------------*/
	// On met d'abord toutes les pattes du LCD � 1 sauf le backlight
        LCD_RS_W = 1;
        LCD_RW_W = 1;
        LCD_E_W = 1;
        LCD_BL_W = 0;
        LCD_DB4_W = 1;
        LCD_DB5_W = 1;
        LCD_DB6_W = 1;
        LCD_DB7_W = 1;
        // Puis on configure toutes les pattes en sortie, lorsqu'on aura besoin, on modifiera
        // ce qu'il faut en entr�e
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
	// Par s�curit�, on met tout en entr�e au d�part 
	TRISCbits.TRISC13 = 0; //STBY_HBRIDGE en entr�e
	TRISDbits.TRISD12 = 0; //AIN1_HBRIDGE en entr�e
	TRISDbits.TRISD13 = 0; //AIN2_HBRIDGE en entr�e
	TRISDbits.TRISD1 = 0; //PWMA_HBRIDGE en entr�e
	TRISCbits.TRISC1 = 0; //BIN1_HBRIDGE en entr�e
	TRISCbits.TRISC2 = 0; //BIN2_HBRIDGE en entr�e
	TRISDbits.TRISD2 = 0; //PWMB_HBRIDGE en entr�e
	
	/*--------------------------------------------------------*/
	/* XBee
	/*--------------------------------------------------------*/
	TRISFbits.TRISF5 = 0; //XBEE_TX en sortie
	PORTFbits.RF5 = 1; //XBEE_TX = 1
	TRISFbits.TRISF4 = 1; //XBEE_RX en entr�e 
	TRISFbits.TRISF13 = 0; //XBEE_RTS en sortie
	PORTFbits.RF13 = 1; //XBEE_RTS = 1
	TRISFbits.TRISF12 = 1; //XBEE_CTS en entr�e
	TRISGbits.TRISG0 = 1; //XBEE_ON_SLEEP en entr�e
	TRISGbits.TRISG1 = 0; //XBEE_RESET en sortie
	PORTGbits.RG1 = 1; //XBEE_RESET = 1

	/*--------------------------------------------------------*/
	/* RTCC
	/*--------------------------------------------------------*/
        // Supprim� devenu LED7
	// TRISBbits.TRISB10 = 1; //RTCC_MFP en entr�e
}
