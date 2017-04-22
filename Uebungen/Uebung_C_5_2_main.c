/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Uebung_C_4_3_main.c
 * Author: Iwan
 *
 * Created on 4. April 2017, 18:09
 */

#include <stdio.h>
#include <stdlib.h>
#include "Uebung_C_4_3_ampel.h"
#include <unistd.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int punkte[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Positionszeiger
    int *pos;

    // Position auf erstes Element setzen (punkte[0]) 
    pos = punkte;
    printf("(punkte[0]) Wert pos: %d\n", *pos);

    // Position auf naechstes Element setzen (punkte[1])
    pos++;
    printf("(punkte[1]) Wert pos: %d\n", *pos);

    // Position auf 5. Element setzen (punkte[4])
    pos = punkte + 4;
    printf("(punkte[4]) Wert pos: %d\n", *pos);

    // Position auf vorheriges Element setzen (punkte[3])
    pos--;
    printf("(punkte[3]) Wert pos: %d\n", *pos);
}

