#include "Contact.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Nationality.h"

#define PHONE_NUMBER_LENGTH 15

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

char* formatPhoneNumber(char* formattedString, char* phoneNumber, int iterator) {
    
    for(int i = 0; i < PHONE_NUMBER_LENGTH-1; i++)
    {
        if(!isdigit(phoneNumber[i]) || strlen(phoneNumber) > 10) {
            //fprintf(stderr, "This is not a valid phone number.");
            //printf("This is not a valid phone number.\n");
            return NULL;
        }
        switch(i) {
            case(0):
                formattedString[i] = '(';
                break;
            case(4):
                formattedString[i] = ')';
                break;
            case(5):
            case(9):
                formattedString[i] = '-';
                break;
            default:
                formattedString[i] = phoneNumber[iterator];
                iterator++; 
        }
    }
    //formattedString[PHONE_NUMBER_LENGTH - 1] = '\0';
    return formattedString;
}

Contact_Node* createContact(char* firstName, char* lastName, char* phoneNumber, int* Age, char* occupation, char* nationality, struct Dictionary* Dict) {
    struct Contact* Individual = malloc(sizeof(struct Contact));
    strcpy(Individual->firstName, firstName);
    strcpy(Individual->lastName, lastName);
    strcpy(Individual->occupation, occupation);
    char* phoneNumberString;
    phoneNumberString = formatPhoneNumber(phoneNumberString, phoneNumber, 0);
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

void insertContact(AddressBook* AB, Contact_Node* individual){
    unsigned int Index = hashFunction(individual->contact.lastName);
    if(AB->HashTable[Index] == NULL)
    {
       AB->HashTable[Index]->head = individual; 
    }
    else if(AB->HashTable[Index]->head == NULL && AB->HashTable[Index]->head->next == NULL)
    {
        AB->HashTable[Index]->head->next = individual;
    }
    else
    {
       Contact_Node* Contact_Ptr = AB->HashTable[Index]->head;
       while(Contact_Ptr->next != NULL && strcmp(Contact_Ptr->contact.lastName, individual->contact.lastName) <= 0) {
          if(strcmp(Contact_Ptr->contact.lastName, individual->contact.lastName) == 0) {
                if(strcmp(Contact_Ptr->contact.firstName, individual->contact.firstName) == 0) {
                    fprintf(stderr, "This contact already exists.");
                }
                else if(strcmp(Contact_Ptr->contact.firstName, individual->contact.firstName) < 0) {
                    break;
                }
          }
          Contact_Ptr =  Contact_Ptr->next;
       }
       individual->next = Contact_Ptr->next;
       Contact_Ptr->next = individual;

    }
    AB->quantity++;
    
}
void removeContact(AddressBook* AB, Contact_Node* individual) {
    unsigned int Index = hashFunction(individual->contact.lastName);
    Contact_Node* locator = AB->HashTable[Index]->head;
    if(locator == individual)
    {
        
        free(locator);
    }
}

void removeAddressBook(AddressBook* AB) {

}