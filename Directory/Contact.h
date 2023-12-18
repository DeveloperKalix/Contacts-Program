#ifndef CONTACT_H
#define CONTACT_H

#include "Nationality.h"

#define MAX_ORGS 3
#define ORG_LENGTH 50
#define ADDRESS_BOOK_LENGTH 27
#define CONTACT_LIST_LENGTH 64



typedef struct Contact {
    char firstName[25];
    char lastName[25];
    char phoneNumber[11];
    int Age;
    char occupation[50];
    char nationality;
} Contact;

typedef struct Contact_Node {
    Contact contact;
    struct Contact_Node* next;
} Contact_Node;

typedef struct Contact_List {
    struct Contact_Node* head;
    char letter;
}Contact_List;

typedef struct AddressBook {
    char title[25];
    int quantity;
    Contact_List* HashTable[ADDRESS_BOOK_LENGTH];
} AddressBook; 

AddressBook* createAddressBook(char* Title);
Contact_Node* createContact(char* firstName, char* lastName, char* phoneNumber, int* Age, char* occupation, char* nationality, struct Dictionary* Dict);
void insertContact(AddressBook* AB, Contact_Node* individual);
void removeContact(AddressBook* AB, Contact_Node* individual);
unsigned int hashFunction(char* lastName);
void removeAddressBook(AddressBook* AB);
char* formatPhoneNumber(char* formattedString, char* phoneNumber, int iterator);

#endif