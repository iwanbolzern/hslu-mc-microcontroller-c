/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AddressVerwaltung_Address.h
 * Author: Iwan
 *
 * Created on 8. April 2017, 15:47
 */

#ifndef ADDRESSVERWALTUNG_ADDRESS_H
#define ADDRESSVERWALTUNG_ADDRESS_H

typedef struct address_ {
    char* firstName;
    char* name;
    char* street;
    short streetNr;
    short zip;
    char* city;
} address_t;

typedef address_t* AddressPtr_t;

void insertNewAddress(AddressPtr_t* newAddress);

void printAddress(AddressPtr_t addr); 

#endif /* ADDRESSVERWALTUNG_ADDRESS_H */

