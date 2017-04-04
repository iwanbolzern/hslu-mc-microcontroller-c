/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Uebung_C_4_4_queue.c
 * Author: Iwan
 *
 * Created on 4. April 2017, 18:41
 */

#include <stdio.h>
#include <stdlib.h>

#include "Uebung_C_4_4_queue.h"

queueEntry_t* head = NULL;
queueEntry_t* tail = NULL;


void initialize(void) {
    
}

void enqueue(int msg) {
    queueEntry_t* entry = (queueEntry_t*)malloc(sizeof(queueEntry_t));
    entry->msg = msg;
    entry->nextEntry = NULL;
    
    if(tail != NULL) {
        tail->nextEntry = entry;
    }
    if(head == NULL) {
        head = entry;
    }
    
    tail = entry;
}

int dequeue(void) {
    if(head == NULL) {
        printf("Nothing to deqeue!!");
        return -1;
    }
    
    queueEntry_t* entry = head;
    int msg = entry->msg;
    if(head == tail) {
        tail = NULL;
    }
    head = head->nextEntry;
    free(entry);
    return msg;
}

