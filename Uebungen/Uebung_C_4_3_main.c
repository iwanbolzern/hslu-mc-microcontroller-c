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
    while(1) {
        printState();
        nextState();
        sleep(5);
    }
}

