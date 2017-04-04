#include <stdio.h>
#include "Uebung_C_4_3_ampel.h"

static ampelState_t state = RED;

ampelState_t getState(void) {
    return state;
}

void nextState() { 
    if(state == YELLOW)
        state = RED;
    else
        state++;
}

void printState(void) {
    printf("Current State is: %d\n", state);
}



