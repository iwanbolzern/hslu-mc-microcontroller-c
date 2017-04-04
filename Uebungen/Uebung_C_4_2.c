#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) x < y ? x : y
#define MAX(x, y) x > y ? x : y
#define SWAP(t, x, y) t temp = x; x = y; y = temp

/*
 * 
 */
int main(int argc, char** argv) {
    printf("Min von 3 und 4 ist: %d\n", MIN(3, 4));
    printf("Max von 3 und 4 ist: %d\n", MAX(3, 4));
    int x = 3;
    int y = 4; 
    SWAP(int, x, y);
    printf("X: %d Y: %d", x, y);
}

