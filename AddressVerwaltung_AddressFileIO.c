#include <stdio.h>
#include <stdlib.h>
#include "AddressVerwaltung_Address.h"
#include "AddressVerwaltung_DataHolder.h"
#include "Uebungen/dynamicInput.h"


static char* filename = "addresses.csv";

void checkFile(FILE*);

void saveToFile() {
    FILE* csvFile;
    csvFile = fopen(filename, "w+");
    checkFile(csvFile);
    fprintf(csvFile, "Surname\tName\tStreet\tStreet Nr\tZIP\tCity\n");

    AddressPtr_t* allAddresses;
    int size = getAddresses(&allAddresses);
    for (int i = 0; i < size; i++) {
        AddressPtr_t add = *(allAddresses + i);
        fprintf(csvFile, "%s\t%s\t%s\t%d\t%d\t%s\n", add->name, add->firstName,
                add->street, add->streetNr, add->zip, add->city);
    }

    fclose(csvFile);
}

void readFromFile() {
    FILE* csvFile;
    csvFile = fopen(filename, "r+");
    checkFile(csvFile);
    
    // skip first line
    char* metaLine = readUntil(csvFile, '\n');
    free(metaLine);
    
    while(fgetc(csvFile) != EOF) {
        fseek(csvFile, -1, SEEK_CUR); // because one char is read
        AddressPtr_t newAdd = allocAddress();
        newAdd->name = readUntil(csvFile, '\t');
        newAdd->firstName = readUntil(csvFile, '\t');
        newAdd->street = readUntil(csvFile, '\t');
        char* streetNr = readUntil(csvFile, '\t');
        newAdd->streetNr = atoi(streetNr);
        free(streetNr);
        char* zip = readUntil(csvFile, '\t');
        newAdd->zip = atoi(zip);
        free(zip);
        newAdd->city = readUntil(csvFile, '\n');
        addAddress(newAdd);
    }
    
}

void checkFile(FILE* file) {
    if (file == NULL) {
        printf(stderr, "Error during open of csv file\n");
        exit(EXIT_FAILURE);
    } 
}


