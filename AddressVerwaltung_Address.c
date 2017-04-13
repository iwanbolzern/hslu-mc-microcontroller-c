/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AddressVerwaltung_Address.c
 * Author: Iwan
 *
 * Created on 8. April 2017, 15:44
 */

#include <stdio.h>
#include <stdlib.h>
#include "AddressVerwaltung_Address.h"
#include "AddressVerwaltung_DataHolder.h"

void printAddresses();

int main(int argc, char** argv) {
    char c;
    do {
        printf("\n");
        printf("N --> New address\n");
        printf("L --> List addresses\n");
        printf("R --> Read addresses from file\n");
        printf("S --> Save addresses to file\n");
        printf("1 --> Sort list by name\n");
        printf("2 --> Sort list by street\n");
        printf("3 --> Sort list by city\n");
        printf("Q --> Quit\n\n");
        while (!isalnum(c = getchar())); // Solange einlesen bis Zahl oder Buchstabe
        c = toupper(c);
        
            // clear input buffer
        char clear;
        while ((clear = getchar()) != '\n' && clear != EOF) { }
        
        switch (c) {
            case 'N': {
                AddressPtr_t newAddress;
                insertNewAddress(&newAddress);
                addAddress(newAddress);
                break;
            }
            case 'L':
                printAddresses();
                break;

        }
    } while (c != 'Q');
    return (EXIT_SUCCESS);
}

void printAddresses() {
    int size;
    AddressPtr_t* allAddresses;
    size = getAddresses(&allAddresses);
    for(int i = 0; i < size; i++)
        printAddress(*(allAddresses + i));
    
}