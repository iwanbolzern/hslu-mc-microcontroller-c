/*
 * File:   main.c
 * Author: Tamara Toma
 *
 * Created on 20 March 2017, 14:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>  /* für ptrdiff_t */
#include <mem.h>

/**
 * Liest eine Zeile von maximal limit Zeichen ein.
 * Die Zeichen werden (inklusive Zeilenende-Zeichen) im übergebenen * Vektor s /0 terminiert abgelegt.
 * @param s Zeiger auf den Vektor zum Speichern der Eingabe
 * @param limit Maximale Grösse des Vektors
 * @return Anzahl eingelesene Zeichen
 */
int readLine(char s[], int limit) {
    int i = 0;
    int c;
    c = getchar(); /* Buchstabe einlesen */
    while ((c != EOF) && /* Ende File ... */
           (c != '\n') && /* oder Ende Zeile ... */
           (i < limit - 1)) { /* oder Limite des Speichers? */
        s[i] = c;
        i++;
        c = getchar();
    }
    if (c == '\n') {
        s[i] = '\n'; /* Zeilenumbruch anfügen! */
        i++;
    }
    s[i] = '\0'; /* Zeichenkette-Ende anfügen! */
    return i; /* Anzahl gelesene Zeichen zurückgeben */
}

/**
 * Das erste und das letzte Zeichen werden vertauscht.
 * @param firstChar Erstes Zeichen
 * @param lastChar Letztes Zeichen
 */
void swap(char *firstChar, char *lastChar) {
    char c = *firstChar;
    *firstChar = *lastChar;
    *lastChar = c;
}

/**
 * Gibt den String aus.
 * @param charArray char Array
 */
void printString(const char *charArray) {

    for (; *charArray != NULL; ++charArray) {
        printf("%c", *charArray);//Array wird auf die Konsole ausgegeben
    }
}

/**
 * Eingelesene String wird umgekehrt ausgegeben.
 */
void reverse() {
    const int maxLength = 10; //Maximale Grösse des Vektors
    char s[maxLength]; //Vektor mit maximalen Länge

    int length = readLine(s, maxLength); //Anzahl Zeichen

    for (int i = 0; i < length / 2; i++) { //Anzahl Zeichen mit zwei dividieren um die erste Hälfte
        // mit der anderen Hälfte zu vertauschen.
        swap(&s[i], &s[length - i - 2]); // -2, um "/n" zu ignorieren
    }

    printString(s);
}

/**
 *  Main
 * @return void
 */
void main(void) {
    reverse();
}

