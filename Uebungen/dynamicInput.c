#include <stdio.h>
#include <stdlib.h>
#include "dynamicInput.h"

char* read() {
	char zeichen;
	int i = 0;
	char* input = (char*) malloc(sizeof(char));

	puts("Zu speichernder Text eingeben: ");

	do {
		zeichen = (char) getchar();
		input = (char*) realloc(input, sizeof(char) * (i + 1));
		if (zeichen != '\n') {
			*(input + i) = zeichen;
			i++;
		}
	} while (zeichen != '\n');

	*(input + i) = '\0';

	return input;
}

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	char* input = read();

	printf("Die eingegebene Zeichenfolge ist: \n%s\n", input);

	free(input);
	getchar();
	return (EXIT_SUCCESS);
}
