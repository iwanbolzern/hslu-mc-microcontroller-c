#include <stdio.h>
#include "Uebung_C_4_1_calc.h"

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

/* push: f auf den Stack bringen */
void push(double f) {
    if(sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("Stack ist foll");
    }
}

/*pop: Wert von Stack holen und liefern */
double pop(void) {
    if(sp > 0) {
        return val[--sp];
    } else {
        printf("STack ist leer");
    }
    return 0;
}


