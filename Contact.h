#ifndef NATIONALITY_H

#define MAX_ORGS 3
#define ORG_LENGTH 50
#define ADDRESS_LENGTH_SIZE 65



typedef struct Contact {
    char firstName[25];
    char lastName[25];
    char phoneNumber[11];
    int Age;
    char occupation[50];
    char organizations[MAX_ORGS][ORG_LENGTH];
    char nationality[1];
} Contact;

typedef struct Contact_Node {
    Contact contact;
    struct Contact_Node* next;
} Contact_Node;

typedef struct AddressBook {
    char title[25];
    Contact_Node* HashTable[ADDRESS_LENGTH_SIZE];
} AddressBook; 

unsigned int hashFunction()

#endif