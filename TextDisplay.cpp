/**
 * Fichier : TextDisplay.cpp
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Pilote orient� object pour affichage LCD bas� sur un circuit
 * Hitachi HD44780 ou compatible
 *
 * Ce pilote est destin� au circuit "Starter-kit PIC32" de l'ETML-ES
 *
 * Ce code est bas� sur:
 *     - Le fichier Mc32DriverLcd.c de Gomes Andres (ETML-ES)
 */

#include "GenericTypeDefs.h"

#include "p32mx795f512l.h"
#include "SK32MX795F512L.h"
#include "Mc32Delays.h"


#include "TextDisplay.h"

/******************************************************************************
 * CONSTANTE
 ******************************************************************************/
namespace LCD {

    // Commande
    const uint8_t CLEARDISPLAY = 0x01;
    const uint8_t RETURNHOME = 0x02;
    const uint8_t ENTRYMODESET = 0x04;
    const uint8_t DISPLAYCONTROL = 0x08;
    const uint8_t CURSORSHIFT = 0x10;
    const uint8_t FUNCTIONSET = 0x20;
    const uint8_t SETCGRAMADDR = 0x40;
    const uint8_t SETDDRAMADDR = 0x80;

    // Drapeau pour le mode d'affichage
    const uint8_t ENTRYRIGHT = 0x00;
    const uint8_t ENTRYLEFT = 0x02;
    const uint8_t ENTRYSHIFTINCREMENT = 0x01;
    const uint8_t ENTRYSHIFTDECREMENT = 0x00;

    // Drapeau pour la gestion de l'affichage
    const uint8_t DISPLAYON = 0x04;
    const uint8_t DISPLAYOFF = 0x00;
    const uint8_t CURSORON = 0x02;
    const uint8_t CURSOROFF = 0x00;
    const uint8_t BLINKON = 0x01;
    const uint8_t BLINKOFF = 0x00;

    // Drapeau pour les d�placements d'�crane et de curseur
    const uint8_t DISPLAYMOVE = 0x08;
    const uint8_t CURSORMOVE = 0x00;
    const uint8_t MOVERIGHT = 0x04;
    const uint8_t MOVELEFT = 0x00;

    // Drapeau pour l'initialisation
    const uint8_t BIT8MODE = 0x10;
    const uint8_t BIT4MODE = 0x00;
    const uint8_t LINE2 = 0x08;
    const uint8_t LINE1 = 0x00;
    const uint8_t DOTS5x10 = 0x04;
    const uint8_t DOTS5x8 = 0x00;
}


/******************************************************************************
 * FONCTION PUBLIQUE
 ******************************************************************************/
TextDisplay::TextDisplay() {
    /*--------------------------------------------------------*/
    /* D�finition du tableau pour l'adresse des lignes
    /*--------------------------------------------------------*/
    M_LINES_ADRESS[0] = 0; // Non utilis�
    M_LINES_ADRESS[1] = 0; // Adresse de la ligne 1
    M_LINES_ADRESS[2] = 64;
    M_LINES_ADRESS[3] = 20;
    M_LINES_ADRESS[4] = 84; // Adresse de la ligne 4

    
     enable_backlight();

    // on va effectuer exactement ce que demande le ks0066
    // on repositionne LCD_E tout pour un d�marrage correct
    LCD_E_W = 0;
    delay_us(1); // si LCD_E �tait � 1, on attend
    LCD_RS_W = 0;  // demand� pour une commande
    LCD_RW_W = 0;
    // suivant comment l'interfa�age avec le LCD s'est arr�t�, il faut tout remettre � plat
    // selon les notes d'applications, il faut envoyer 3 fois un nibble 0x3
    // pour lui faire croire que nous sommes en interface8 bits
    // chaque envoi doit �tre s�par� de 5ms!!
    send_nibble(0x03); // correspond � 0x30, interface 8 bits
    delay_ms(5);
    send_nibble(0x03); // correspond � 0x30, interface 8 bits
    delay_ms(5);
    send_nibble(0x03); // correspond � 0x30, interface 8 bits
    delay_ms(5);
    // maintenant, on peut configurer notre LCD en interface 4 bits
    LCD_RS_W = 0;  // demand� pour une commande (on assure!)
    send_nibble(2);// 4 bits interface

    command(LCD::DISPLAYCONTROL | LCD::LINE2 | LCD::DISPLAYOFF);
    delay_us(40); //ds0066 demande >39us

    // Initilisation du mode par d�faut:
     m_display_control = LCD::DISPLAYON | LCD::CURSOROFF | LCD::BLINKOFF;
    command( LCD::DISPLAYCONTROL | m_display_control);
    delay_us(40); //ds0066 demande >39us

    // Effacage de l'�cran
    clear();
    
    // Initilisation du sens du texte
    m_display_mode = LCD::ENTRYLEFT | LCD::ENTRYSHIFTDECREMENT;
    command(LCD::ENTRYMODESET | m_display_mode);

    delay_us(40); //ds0066 demande >39us
}

void TextDisplay::print(const char *ptr_char) {
    while (*ptr_char != 0)
    {
        write(*ptr_char);
    	ptr_char++;
    }
}

void TextDisplay::write(const uint8_t c) {
    switch (c) {
        case '\f':
            send_byte(1,1);
            break;
     	case '\n':
            set_cursor(1,2);
            break;
     	case '\b':
            send_byte(0,0x10);
            break;
        case '\t':
            // Caract�re de tabulation -> quatre espace blanc
            send_byte(1,' ');
            send_byte(1,' ');
            send_byte(1,' ');
            send_byte(1,' ');
            break;
     	default:
            send_byte(1,c);
            break;
   }
}

void TextDisplay::home(void)
{
  command(LCD::RETURNHOME); 
  delay_ms(2);
}

void TextDisplay::set_cursor(uint8_t x, uint8_t y) {
   uint8_t address;
   address = M_LINES_ADRESS[y];
   address+=x-1;
   send_byte(0,0x80|address);

}

void TextDisplay::enable_backlight(void) {
    LCD_BL_T = 0;
    LCD_BL_W = 1;
}

void TextDisplay::disable_backlight(void) {
    LCD_BL_T = 0;
    LCD_BL_W = 0;
}

void TextDisplay::clear( void )
{
    command(LCD::CLEARDISPLAY);
    delay_ms(2);
}

void TextDisplay::disable_display(void) {
  m_display_control &= ~LCD::DISPLAYON;
  command( LCD::DISPLAYCONTROL | m_display_control);
}
void TextDisplay::enable_display(void) {
  m_display_control |= LCD::DISPLAYON;
  command( LCD::DISPLAYCONTROL | m_display_control);
}

void TextDisplay::enable_blinking_cursor( void )
{
    m_display_control |= LCD::BLINKON;
    command( LCD::DISPLAYCONTROL | m_display_control);
    delay_ms(2);
}

void TextDisplay::disable_blinking_cursor( void )
{
    m_display_control &= ~LCD::BLINKON;
    command( LCD::DISPLAYCONTROL | m_display_control);
    delay_ms(2);
}

void TextDisplay::disable_underline_cursor(void) {
  m_display_control &= ~LCD::CURSORON;
   command(LCD::DISPLAYCONTROL | m_display_control);
}
void TextDisplay::enable_underline_cursor(void) {
  m_display_control |= LCD::CURSORON;
  command(LCD::DISPLAYCONTROL | m_display_control);
}


// This will 'right justify' text from the cursor
void TextDisplay::enable_autoscroll(void) {
  m_display_mode |= LCD::ENTRYSHIFTINCREMENT;
  command(LCD::ENTRYMODESET | m_display_mode);
}

// This will 'left justify' text from the cursor
void TextDisplay::disable_autoscroll(void) {
  m_display_mode &= ~LCD::ENTRYSHIFTINCREMENT;
  command(LCD::ENTRYMODESET | m_display_mode);
}

// These commands scroll the display without changing the RAM
void TextDisplay::scroll_left(void) {
  command(LCD::CURSORSHIFT | LCD::DISPLAYMOVE | LCD::MOVELEFT);
}
void TextDisplay::scroll_right(void) {
  command(LCD::CURSORSHIFT | LCD::DISPLAYMOVE | LCD::MOVERIGHT);
}

TextDisplay::~TextDisplay() {
}

/******************************************************************************
 * FONCTION PRIVEE
 ******************************************************************************/

void TextDisplay::command(uint8_t value) {
    send_byte(0, value);
}

void TextDisplay::send_byte(uint8_t address, uint8_t n) {
    LCD_RS_W = 0;

    while ( (read_byte() & 0x80) == 0x80 ){
    };

    LCD_RS_W = address;
    LCD_RW_W = 0;

    //LCD_E d�j� � 0
    send_nibble(n >> 4);
    send_nibble(n & 0xf);
}

void TextDisplay::send_nibble(uint8_t n) {
   UINT8_BITS NibbleToWrite;
   NibbleToWrite.Val = n;
   LCD_DB7_W = NibbleToWrite.bits.b3;
   LCD_DB6_W = NibbleToWrite.bits.b2;
   LCD_DB5_W = NibbleToWrite.bits.b1;
   LCD_DB4_W = NibbleToWrite.bits.b0;
   delay500ns();
   LCD_E_W = 1;
   delay500ns(); // E pulse width min = 450ns pour le 1!
   LCD_E_W = 0;
   delay500ns(); // E pulse width min = 450ns �galement pour le 0!
}

/******************************************************************************
 * FONCTION BAS NIVEAU - PRIVE
 ******************************************************************************/

uint8_t TextDisplay::read_byte( void )
{
    UINT8_BITS lcd_read_byte;
    LCD_DB4_T = 1; // 1=input
    LCD_DB5_T = 1;
    LCD_DB6_T = 1;
    LCD_DB7_T = 1;
    LCD_RW_W = 1;
    delay500ns(); //ds0066 demande 0.5us
    LCD_E_W = 1;
    delay500ns(); //ds0066 demande 0.5us
    lcd_read_byte.bits.b7 = LCD_DB7_R;
    lcd_read_byte.bits.b6 = LCD_DB6_R;
    lcd_read_byte.bits.b5 = LCD_DB5_R;
    lcd_read_byte.bits.b4 = LCD_DB4_R;
    LCD_E_W = 0; // attention e pulse min = 500ns � 1 et autant � 0
    delay500ns();
    LCD_E_W = 1;
    delay500ns();
    lcd_read_byte.bits.b3 = LCD_DB7_R;
    lcd_read_byte.bits.b2 = LCD_DB6_R;
    lcd_read_byte.bits.b1 = LCD_DB5_R;
    lcd_read_byte.bits.b0 = LCD_DB4_R;
    LCD_E_W = 0;
    delay500ns();
    LCD_DB4_T = 0; // 0=output
    LCD_DB5_T = 0;
    LCD_DB6_T = 0;
    LCD_DB7_T = 0;

    return(lcd_read_byte.Val);
}

char TextDisplay::read( uint8_t x, uint8_t y)
{
    uint8_t value;
    set_cursor(x,y);
    while ( read_byte() & 0x80 ){
    }; // wait until busy flag is low
    LCD_RS_W = 1;
    value = read_byte();
    LCD_RS_W = 0;
    return(value);
}


/******************************************************************************
 * LICENSE
 ******************************************************************************/

/*
 * Copyright (c) 2014, �cole sup�rieur de l'ETML <www.etml-es.ch>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */