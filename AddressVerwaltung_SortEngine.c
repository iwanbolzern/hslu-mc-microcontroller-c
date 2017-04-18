#include "AddressVerwaltung_Address.h"
#include "AddressVerwaltung_DataHolder.h"
#include <stdlib.h>


int sort(AddressPtr_t** sortedAddresses, int(*sortFuntion)(const void* elem1, const void* elem2)) {
    int size = getAddresses(sortedAddresses);
    
    qsort(*sortedAddresses, size, sizeof(AddressPtr_t), sortFuntion);
    
    return size;
}

int byName(const AddressPtr_t* elem1, const AddressPtr_t* elem2) {
    return strcmp((*elem1)->name, (*elem2)->name);
}

int byStreet(const AddressPtr_t* elem1, const AddressPtr_t* elem2) {
    return strcmp((*elem1)->street, (*elem2)->street);
}

int byCity(const AddressPtr_t* elem1, const AddressPtr_t* elem2) {
    return strcmp((*elem1)->city, (*elem2)->city);
}



