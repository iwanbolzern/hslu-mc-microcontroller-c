/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Uebung_C_4_4_queue.h
 * Author: Iwan
 *
 * Created on 4. April 2017, 18:41
 */

#ifndef UEBUNG_C_4_4_QUEUE_H
#define UEBUNG_C_4_4_QUEUE_H

typedef struct queueEntry {
    int msg;
    struct queueEntry* nextEntry;
} queueEntry_t;

void initialize(void);

void enqueue(int msg);

int dequeue(void);

#endif /* UEBUNG_C_4_4_QUEUE_H */

