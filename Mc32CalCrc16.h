#ifndef MC32CALCCRC16_H
#define MC32CALCCRC16_H

/*--------------------------------------------------------*/
/*	Mc32CalcCrc16.h
/*--------------------------------------------------------*/

// Fonction pour calcul d'un CRC16-CCITT
// Adaptation PIC du programme de Michael Neumann, 14.06.1998
// Migration sur PIC32MX 26.03.2014 C. Huber

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

// Important : selon spec. CCITT il faut initialiser la valeur du
// Crc16 à 0xFFFF


// Fonction pour calcul du CRC16 byte à byte
// -----------------------------------------

// Il faut fournir la valeur précédante du CRC ainsi qu'un 
// des caractère du message
// La fonction retourne la nouvelle valeur du CRC16

uint16 updateCRC16(uint16 crc, uint8 data);

#endif