/*
 * menu.h
 *
 *  Created on: 11.03.2017
 *      Author: Iwan
 */

#ifndef MENU_H_
#define MENU_H_

struct menuItem {
	char item;
	void (*functionPtr)();
	char description[100];
};

void findMenuItem(struct menuItem menuItems[], int size, char input);

void printMenu(struct menuItem menuItems[], int size);

void doA();

void doB();

void doC();

void doQ();

#endif /* MENU_H_ */
