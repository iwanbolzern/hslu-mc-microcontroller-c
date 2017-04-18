#include <stddef.h>
#include <stdlib.h>

#include "AddressVerwaltung_Address.h"

void* malloc_e(size_t size);
void* realloc_e(void* oldMem, size_t size);
void free_mem(AddressPtr_t address);

static AddressPtr_t* addresses = NULL;
static int size = 0;

AddressPtr_t allocAddress() {
    return (AddressPtr_t)malloc_e(sizeof(address_t));
}

void addAddress(AddressPtr_t address) {
    if(addresses == NULL) {
        addresses = (AddressPtr_t*)malloc_e(sizeof(AddressPtr_t));
        *addresses = address;
    } else {
        addresses = (AddressPtr_t*)realloc_e(addresses, sizeof(AddressPtr_t) * (size + 1));
        *(addresses + size) = address;
    }
    size++;
}

void* malloc_e(size_t size) {
    void* mem = malloc(size);
    if(mem == NULL) {
        printf("Something went wrong during memory allocation. Go and buy more RAM!");
        exit(-1);
    }
    return mem;
}

void* realloc_e(void* oldMem, size_t size) {
    void* mem = realloc(oldMem, size);
    if(mem == NULL) {
        printf("Something went wrong during memory allocation. Go and buy more RAM!");
        exit(-1);
    }
    return mem;
}


void removeAddress(AddressPtr_t address) {
    
}

void clearAll() {
    for(int i = 0; i < size; i++) {
        free_mem(addresses[i]);
        addresses[i] = NULL;
    }
    free(addresses);
    addresses = NULL;
}

void free_mem(AddressPtr_t address) {
    free(address->city);
    free(address->firstName);
    free(address->name);
    free(address->street);
    free(address);
}

int getAddresses(AddressPtr_t** callbackAddresses) {
    *callbackAddresses = addresses;
    return size;
}

