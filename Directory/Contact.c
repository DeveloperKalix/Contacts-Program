#include "Contact.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Nationality.h"

AddressBook* createAddressBook(char* Title){
    // Allocates memory and initializes the Address Book.
    struct AddressBook* AB = malloc(sizeof(struct AddressBook));
    strcpy(AB->title, Title);
    AB->quantity = 0;
    char letter = 'A';
    for(int i = 0; i < ADDRESS_BOOK_LENGTH; i++)
    {
        struct Contact_List* letterList = malloc(sizeof(Contact_List));
        letterList->letter = letter;
        letterList->head = NULL;
        letter++;
        AB->HashTable[i] = letterList;
    }
    return AB;
}

Contact_Node* createContact(char* firstName, char* lastName, char* phoneNumber, int* Age, char* occupation, char organizations[][MAX_ORGS], char* nationality, struct Dictionary* Dict) {
    struct Contact* Individual = malloc(sizeof(struct Contact));
    strcpy(Individual->firstName, firstName);
    strcpy(Individual->lastName, lastName);
    strcpy(Individual->occupation, occupation);
    Individual->nationality = *Retrieve(Dict, nationality);
    Individual->Age = *Age;
    struct Contact_Node* contact = malloc(sizeof(struct Contact_Node));
    contact->contact = *Individual;
    contact->next = NULL;
    return contact;
}

unsigned int hashFunction(char* lastName) {
    return (toupper(lastName[0])) % 65;
}

// void insertContact(AddressBook* AB, Contact_Node* individual){

// }
// void removeContact(AddressBook* AB, Contact* individual);

// void removeAddressBook(AddressBook* AB);