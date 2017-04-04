/* 
 * File:   main.c
 * Author: Thushjandan Ponnudurai <thushjandan.ponnudurai@stud.hslu.ch>
 *
 * Created on 25. März 2017, 11:14
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeName_* nodeNamePtr_T;

typedef struct nodeName_ {
    char* firstname;
    char* surame;
    nodeNamePtr_T nextNode;
} nodeName_T;

// Declare methods
nodeNamePtr_T addToList(nodeNamePtr_T parNodeName, char parFirstname[], char parSurname[]);
void printList(nodeNamePtr_T root);

/*
 * Main method
 */
int main(int argc, char** argv) {
    // Initialize variables
    char firstname[100];
    char surname[100];
    nodeNamePtr_T root;
    
    printf("Please enter firstname and surname. Then press Enter.\n");
    printf("To end the input, put a dot (.) at end of the surname\n");
    // If surname contains a dot at the end of the string, then go out from the loop
    while (surname[strlen(surname)-1] != '.'){
        // Scan two strings from command line
        // Delimited by whitespace or line break
        scanf("%s %s", firstname, surname);
        printf("One more?\n");
        printf("To end the input, put a dot (.) at end of the surname\n\n");
        // Add to linked List
        root = addToList(root, firstname, surname);
    }
    
    printf("\n--------------------------------------");
    printf("\nEingetragene Namen:\n");
    printf("--------------------------------------\n\n");
    // Print out the linked list
    printList(root);
    
    return (EXIT_SUCCESS);
}

/**
 * Add a new node to the linkedlist
 * @param parNodeName
 * @param parFirstname
 * @param parSurname
 * @return 
 */
nodeNamePtr_T addToList(nodeNamePtr_T parNodeName, char parFirstname[], char parSurname[]){
    char* firstname;
    char* surname;
    
    if (parNodeName == NULL){
        // Check if last char is a dot
        if (parSurname[strlen(parSurname) - 1] == '.'){
            // Allocate memory for string without the dot
            surname = (char*) malloc(sizeof(char) * (strlen(parSurname)));
            // Do not copy the dot
            strncpy(surname, parSurname, strlen(parSurname) - 1);
        } else {
            // For strings without dot
            surname = (char*) malloc(sizeof(char) * (strlen(parSurname) + 1));
            strcpy(surname, parSurname);
        }
        // Allocate and copy string
        firstname = (char*) malloc(sizeof(char) * strlen(parFirstname) + 1);
        strcpy(firstname, parFirstname);
        
        // Create a new node
        parNodeName = (nodeNamePtr_T) malloc(sizeof(nodeName_T));
        parNodeName->firstname = firstname;
        parNodeName->surame = surname;
        parNodeName->nextNode = NULL;
    } else {
        // Node is occupied, go to the child node (recursive)
        parNodeName->nextNode = addToList(parNodeName->nextNode, parFirstname, parSurname);
    }
    
    return parNodeName;
    
}

/**
 * Print out the linked list with all the names.
 * @param root
 */
void printList(nodeNamePtr_T root){
    if (root != NULL){
        printf("Vorname: %s\t\tNachname: %s\n", root->firstname, root->surame);
        // Print the next node
        printList(root->nextNode);
    }
}

