/**
 * Fichier : TextDisplay.h
 * Auteur  : Samuel Dolt
 * License : BSD 3 clauses
 *
 * Pilote orient� object pour affichage LCD bas� sur un circuit
 * Hitachi HD44780 ou compatible
 *
 * Ce pilote est destin� au circuit "Starter-kit PIC32" de l'ETML-ES
 *
 * Ce code est bas� sur:
 *     - Le fichier t Mc32DriverLcd.c de Gomes Andres (ETML-ES)
 */

#ifndef TEXTDISPLAY_H
#define	TEXTDISPLAY_H

#include <cstdint>
#include <cstdio>

/*
 * Structure permettant de d�finir un nombre et la base dans lequel on
 * veut l'afficher
 */
typedef struct{
    uint8_t base;
    int32_t number;
}convert_s;

/*
 * Permet l'utilisation du code endl
 */
enum stream_symbol {
    endl
};

/*
 * Classe repr�sentant l'�cran LCD. Pour l'instant la classe se base
 * sur le brochage d�finit dans le fichier SK32MX795F512L.h
 *
 * Pour l'instant, la classe g�re uniquement des �crans de 4 lignes
 */
class TextDisplay{
public:

    /*
     *  Constructeur par d�faut de la classe
     */
    TextDisplay();

    /*
     * print permet d'afficher une chaine de caract�re � l'�cran
     * Aucun formatage n'est effectu�
     */
    void print(const char *ptr_char);
    void print(const int32_t number);
    void print(const convert_s data );
    void print(enum stream_symbol symbol);

    /*
     *  write �crit un caract�re sur l'�cran
     */
    void write(const uint8_t c);

    /*
     * D�place le curseur en position 1,1
     */
    void home(void);

    /*
     * D�place le curseur � la position donn� en param�tre
     * - x : N� de ligne de 1 � 4
     * - y : N� de colonne de 1 � 24
     */
    int8_t set_cursor(uint8_t x, uint8_t y);

    /*
     * Active le r�tro�clairage de l'�cran
     */
    void enable_backlight(void);

    /*
     * D�sactive le r�tro�clairage de l'�cran
     */
    void disable_backlight(void);

    /*
     * Efface le contenu de l'�cran
     */
    void clear( void );

    /*
     * D�sactive l'affichage sans effacer son contenu
     */
    void disable_display(void);

    /*
     * Active l'affichage (r�affiche son contenu)
     */
    void enable_display(void);

    /*
     * Active l'affichage du curseur "clignotant"
     */
    void enable_blinking_cursor( void );

    /*
     * D�sactive l'affichage du curseur "clignotant"
     */
    void disable_blinking_cursor( void );

    /*
     * Active l'affichage du curseur "soulign�"
     */
    void disable_underline_cursor(void);

    /*
     * D�sactive l'affichage du curseur "soulign�"
     */
    void enable_underline_cursor(void);


    void enable_autoscroll(void);
    void disable_autoscroll(void);

    /*
     * D�calage � droite de l'affichage
     */
    void scroll_right(void);

    /*
     * D�calage � gauche de l'affichage
     */
    void scroll_left(void);

    /*
     * Destructeur
     */
    virtual ~TextDisplay();
private:
    /*
     * Lecture d'un caract�re
     */
    char read( uint8_t x, uint8_t y);

    /*
     * Envoi d'un caract�re
     */
    void send_byte(uint8_t address, uint8_t n);
    void send_nibble(uint8_t n);
    uint8_t read_byte( void );

    /*
     * Envoi d'une commande
     */
    void command(uint8_t value);

    /*
     * Tableau contenant les adresses de ligne
     */
    uint8_t M_LINES_ADRESS[5];

    /*
     * Taille de l'�cran
     */
    uint8_t M_NUMBER_OF_LINE;
    uint8_t M_NUMBER_OF_COLUMN;

    /*
     * Param�tres de control actuel
     */
    uint8_t m_display_control;

    /*
     * Mode d'affichage actuel
     */
    uint8_t m_display_mode;

    /*
     * Colonne actuelle
     */
    uint8_t m_column;

    /*
     * Ligne actuelle
     */
    uint8_t m_line;

};

/******************************************************************************
 * STREAM SUPPORT
 ******************************************************************************/

/* Template g�n�rique, redirige l'op�rateur lcd << vers lcd.print pour tous les
 * type
 */
template<class T>
inline TextDisplay &operator <<(TextDisplay &stream, const T data)
{ stream.print(data); return stream; }

/******************************************************************************
 * GESTION DES CONVERSIONS
 ******************************************************************************/

namespace convert {
    convert_s to_dec(int32_t number);
    convert_s to_hex(int32_t number);
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

#endif	/* TEXTDISPLAY_H */