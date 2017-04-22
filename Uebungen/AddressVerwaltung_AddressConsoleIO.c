#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AddressVerwaltung_DataHolder.h"
#include "AddressVerwaltung_Address.h"
#include "dynamicInput.h"

int readNumberOrEmpty();
char* readUntilNotEmpty();

void insertNewAddress(AddressPtr_t* newAddress) {
    AddressPtr_t address = allocAddress();
    printf("Firstname:\t");
    address->firstName = readUntilNotEmpty();
    printf("Name:\t");
    address->name = readUntilNotEmpty();
    printf("Street:\t");
    address->street = readUntilNotEmpty();
    printf("Street Nbr:\t");
    address->streetNr = readNumberOrEmpty();
    printf("ZIP:\t");
    address->zip = readNumberOrEmpty();
    printf("City:\t");
    address->city = readUntilNotEmpty();
    *newAddress = address;
}

int readNumberOrEmpty() {
    int input, success;
    int try = 0; 
    do {
        if(try > 5) {
            printf("Realy?!?! You're too stupid for this world...\n");
            printf("Hope see you never again. Bye!");
            exit(-1);
        }
        else if(try > 0)
            printf("Please insert a number or leave empty:\t");

        success = scanf("%d[^\n]",&input);
        char clear;
        while ((clear = getchar()) != '\n' && clear != EOF);
        try++;
    } while(success <= 0);
    return input;
}

char* readUntilNotEmpty() {
    char* input;
    int try = 0; 
    do {
        if(try > 5) {
            printf("Realy?!?! You're too stupid for this world...\n");
            printf("Hope see you never again. Bye!");
            exit(-1);
        }
        else if(try > 0)
            printf("Please insert at least on character:\t");
        
        input = read();
        try++;
    } while(strlen(input) <= 0);
    return input;
}