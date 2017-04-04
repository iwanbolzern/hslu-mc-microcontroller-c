/*
 * manu.c
 *
 *  Created on: 11.03.2017
 *      Author: Iwan
 */

#include <stdio.h>
#include "menu.h"
#include <string.h>

int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	struct menuItem menuItems[] = {
			{'A', &doA, "Select menu A\n\0"},
			{'B', &doB, "Select menu B\n\0"},
			{'C', &doC, "Select menu C\n\0"},
			{'Q', &doQ, "Exit\n\0"}
	};

	while (1) {
		printMenu(menuItems, sizeof(menuItems) / sizeof(struct menuItem));
		printf("Enter selection:\n");
		char s[32];
		// Wait for input
		(void) scanf("%s", s);
		findMenuItem(menuItems, sizeof(menuItems) / sizeof(struct menuItem), s[0]);
	}
}

void findMenuItem(struct menuItem menuItems[], int size, char input) {
	for (int index = 0; index < size; index++) {
		if(input == menuItems[index].item) {
			(*menuItems[index].functionPtr)();
			break;
		}
	}
}

void printMenu(struct menuItem menuItems[], int size) {
	for(int i = 0; i < size; i++) {
		printf("%c --> %s", menuItems[i].item, menuItems[i].description);
	}
}

void doA() {
	printf("Menu A selected\n");
}

void doB() {
	printf("Menu B selected\n");
}

void doC() {
	printf("Menu B selected\n");
}

void doQ() {
	printf("Exit...");
	exit(0);
}

