#include <stdio.h>
#include <ctype.h>
#include "Uebung_C_4_1_calc.h"

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getchar()) == ' ' || c == '\t');
    if (!isdigit(c) && c != '.') {
        s[1] = '\0';
        return (c); /* keine Zahl */
    }
    i = 0;
    if (isdigit(c)) /* ganzzahligen Teil sammeln */
        while (isdigit(s[++i] = c = getchar()));
    s[i] = '\0';
    return (NUMBER);
}
