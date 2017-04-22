/* Copyright 2010 Hochschule Luzern - Technik & Architektur */
#include <stdio.h>
#define N_READ 3

char* stringify(int n_read) {
    int i;
    char* s;
    s = (char*) malloc(sizeof (char)*4 * n_read * 4 + 2);
    for (i = 0; i < n_read - 1; i += 4) {
        s[i] = '%';
        s[i + 1] = 'd';
        s[i + 2] = '\\';
        s[i + 3] = 't';
    }
    s[i] = '%';
    s[i + 1] = 'd';
    s[i + 2] = '\0';
    return (s);
}

/* reads N numbers from the console separated by tabs and displays them*/
int main(int argc, char** argv) {
    int i;
    int iread[N_READ];
    char* sp;
    // char s[4*N_READ+3];
    sp = stringify(N_READ);
    printf("please enter %d numbers with tabs as separator.\nFinish with the ENTER-Key:\n", N_READ);
    for (i = 0; i < N_READ; i++) {
        scanf(sp, &iread[i]); //flexible way of reading any numbers of int
    }
    //this here would be too easy and restrictiv - changing N_READ would cause major changes in the code
    //scanf("%d\t%d\t%d", &iread[0], &iread[1], &iread[2]);
    printf("\nRead values:\n");
    for (i = 0; i < N_READ; i++)
        printf("%d \n", iread[i]);
}