
#include "AddressVerwaltung_Address.h"

void printAddress(AddressPtr_t addr) {
    printf("Name:\t%s %s\n", addr->firstName, addr->name);
    printf("Street/Nbr:\t%s %d\n", addr->street, addr->streetNr);
    printf("ZIP/City:\t%d %s\n", addr->zip, addr->city);
}

