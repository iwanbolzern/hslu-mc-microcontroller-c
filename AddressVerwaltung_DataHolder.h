#ifndef ADDRESSVERWALTUNG_DATAHOLDER_H
#define ADDRESSVERWALTUNG_DATAHOLDER_H

#include "AddressVerwaltung_Address.h"

AddressPtr_t allocAddress();

void addAddress(AddressPtr_t address);

void removeAddress(AddressPtr_t address);

// returns size
int getAddresses(AddressPtr_t** addresses);

#endif /* ADDRESSVERWALTUNG_DATAHOLDER_H */

