#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

/* Zeichen holen mit Buffer */
int getch(void) {
    return bufp > 0 ? buf[--bufp] : getchar();
}

/* Zeichen wieder zurueckstellen wenn zuviel geholt */
void ungetch(int c) {
    if(bufp < BUFSIZE) {
        buf[bufp++] = c;
    } else {
        printf("Buffer ist foll");
    }
}

