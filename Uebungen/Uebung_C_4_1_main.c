#include <stdio.h>
#include <stdlib.h> /* fuer atof() */ /* hier alle Konstanten */
#include "Uebung_C_4_1_calc.h"

#define MAXOP 100 /* max Laenge von Operand und/oder Operator */

int main() {
    int type;
    char s[MAXOP];
    double op2;
    
    freopen("inputfile1.txt", "r", stdin);
    //Oeffnet das File "inputfile.txt" in dem Pfad von main.c und nimmt das File als //Standard Eingabe anstelle Tastatur
    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0) {
                    push(pop() - op2);
                } else {
                    printf("divided by 0 error");
                }
                break;
            default:
                printf("Kommando nicht bekannt");
                break;
        }
    }
    fclose(stdin); // Schliesst die Standard-Eingabe stdin (das File von freopen)
    return (0);
}





