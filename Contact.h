#ifndef NATIONALITY_H

#define MAX_ORGS 3
#define ORG_LENGTH 50
#define ADDRESS_BOOK_SIZE 65



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
    struct Node* next;
} Contact_Node;

struct AddressBook {
    char title[25];
    
};

typedef struct {
    HashTable AddressBook;
}

#endif