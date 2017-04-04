/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Uebung_C_4_4_main.c
 * Author: Iwan
 *
 * Created on 4. April 2017, 19:05
 */

#include <stdio.h>
#include <stdlib.h>
#include "Uebung_C_4_4_queue.h"

/*
 * 
 */
int main(int argc, char** argv) {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    
}

