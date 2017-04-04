/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Uebung_C_4_3_ampel.h
 * Author: Iwan
 *
 * Created on 4. April 2017, 18:10
 */

#ifndef UEBUNG_C_4_3_AMPEL_H
#define UEBUNG_C_4_3_AMPEL_H

typedef enum ampelState {
    RED = 0,
    GREEN = 1,
    GREEN_BLINKING = 2,
    YELLOW = 3
} ampelState_t;

ampelState_t getState(void);

void nextState(void);

void printState(void);

#endif /* UEBUNG_C_4_3_AMPEL_H */

