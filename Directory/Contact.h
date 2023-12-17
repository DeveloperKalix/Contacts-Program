#ifndef NATIONALITY_H

#define MAX_ORGS 3
#define ORG_LENGTH 50
#define ADDRESS_BOOK_LENGTH 27



typedef struct Contact {
    char firstName[25];
    char lastName[25];
    char phoneNumber[11];
    int Age;
    char occupation[50];
    char organizations[ORG_LENGTH][MAX_ORGS];
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
Contact_Node* createContact(char* firstName, char* lastName, char* phoneNumber, int* Age, char* occupation, char organizations[][MAX_ORGS], char* nationality, struct Dictionary* Dict);
void insertContact(AddressBook* AB, Contact* individual);
void removeContact(AddressBook* AB, Contact* individual);
unsigned int hashFunction(char* lastName);
void removeAddressBook(AddressBook* AB);

#endif