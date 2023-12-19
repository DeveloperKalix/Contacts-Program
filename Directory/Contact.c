#include "Contact.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Nationality.h"

#define PHONE_NUMBER_LENGTH 16

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

char* formatPhoneNumber(char* phoneNumber, int iterator) {
    printf("PASSED VALUE: %s\n", phoneNumber);
    char* formattedPN = malloc(sizeof(char) * 15);
    if(strlen(phoneNumber) == 10) {
        for(int i = 0; i < PHONE_NUMBER_LENGTH-1; i++)
        {
            switch(i) {
                case(0):
                    formattedPN[i] = '(';
                    break;
                case(4):
                    formattedPN[i] = ')';
                    break;
                case(5):
                case(9):
                    formattedPN[i] = '-';
                    break;
                default:
                    formattedPN[i] = phoneNumber[iterator];
                    iterator++; 
            }
        }
        //formattedPN[PHONE_NUMBER_LENGTH - 1] = '\0';
        //printf("REFORMATTED: %s\n", formattedString);
        return formattedPN;
    }

    return NULL;
    
}

Contact_Node* createContact(char* firstName, char* lastName, char* phoneNumber, int* Age, char* occupation, char* nationality, struct Dictionary* Dict) {
    struct Contact* Individual = malloc(sizeof(struct Contact));
    strcpy(Individual->firstName, firstName);
    strcpy(Individual->lastName, lastName);
    strcpy(Individual->occupation, occupation);
    // printf("KEY: %s\n", nationality);
    char* phoneNumberString;
    if(formatPhoneNumber(phoneNumber, 0)) {
        phoneNumberString = formatPhoneNumber( phoneNumber, 0);
        printf("PHONE NUMBA!: %s\n", phoneNumberString);
        strcpy(Individual->phoneNumber, phoneNumberString);
        free(phoneNumberString);
    }
    else
    {
        fprintf(stderr, "Invalid phone number.");
    }
    // printf("HELLO? %s\n", nationality);
    strcpy(Individual->nationality, nationality);
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
    if(AB->HashTable[Index]->head == NULL)
    {
       AB->HashTable[Index]->head = individual;
    }
    // else if(AB->HashTable[Index]->head != NULL && AB->HashTable[Index]->head->next == NULL)
    // {
    //     int alphacheck = strcmp(AB->HashTable[Index]->head->contact.lastName, individual->contact.lastName);
    //     if(alphacheck < 0)
    //     {
    //         individual->next = AB->HashTable[Index]->head;
    //         AB->HashTable[Index]->head = individual;
    //     }
    //     else if(alphacheck == 0) {
    //         fprintf(stderr, "This contact already exists.");
    //     }
    //     else
    //     {
    //         AB->HashTable[Index]->head->next = individual;
    //     }
    // }
    else
    {
       Contact_Node* Contact_Ptr = AB->HashTable[Index]->head;
       Contact_Node* priorContact = NULL;
       while(Contact_Ptr != NULL && strcmp(Contact_Ptr->contact.lastName, individual->contact.lastName) < 0) {
          if(strcmp(Contact_Ptr->contact.lastName, individual->contact.lastName) == 0) {
                if(strcmp(Contact_Ptr->contact.firstName, individual->contact.firstName) == 0) {
                    fprintf(stderr, "This contact already exists.");
                }
                else if(strcmp(Contact_Ptr->contact.firstName, individual->contact.firstName) < 0) {
                    break;
                }
          }
          priorContact = Contact_Ptr;
          Contact_Ptr =  Contact_Ptr->next;
       }
       if(Contact_Ptr == AB->HashTable[Index]->head) {
            individual->next = AB->HashTable[Index]->head;
            AB->HashTable[Index]->head = individual;
       }
       else
       {
            priorContact->next = individual;
            individual->next = Contact_Ptr;
       }
       
       

    }
    AB->quantity++;
    
}
void removeContact(AddressBook* AB, char* firstName, char* lastName) {
    unsigned int Index = hashFunction(lastName);
    Contact_Node* locator = AB->HashTable[Index]->head;
    if(locator == NULL)
    {
        return;
    }
    else if(locator != NULL && strcmp(locator->contact.firstName, firstName) == 0 && strcmp(locator->contact.lastName, lastName) == 0)
    {
        AB->HashTable[Index]->head = AB->HashTable[Index]->head->next;
        free(locator);
    }
    else
    {
        Contact_Node* PriorContact = locator;
        locator = locator->next;
        while(locator) {
            if(strcmp(locator->contact.firstName, firstName) == 0 && strcmp(locator->contact.lastName, lastName) == 0) {
                PriorContact->next = locator->next;
                free(locator);
                break;
                
            }
            PriorContact = locator;
            locator = locator->next;
       }
       
    }
    printAddressBook(AB);
}

void removeAddressBook(AddressBook* AB) {
    Contact_Node* liberator = NULL;
    for(int index = 0; index < ADDRESS_BOOK_LENGTH; index++)
    {
        Contact_Node* contactIndex = AB->HashTable[index]->head;
        while(contactIndex) {
            liberator = contactIndex;
            contactIndex = contactIndex->next;
            //free(liberator->contact.nationality);
            free(liberator);
        }
        free(AB->HashTable[index]);
    }
    
    return;
}

void printAddressBook(AddressBook* AB) {
    printf("[------------[%s]------------]\n", AB->title);
    for(int index = 0; index < ADDRESS_BOOK_LENGTH; index++) {
        Contact_Node* contact = AB->HashTable[index]->head;
        printf("[%c]\n", AB->HashTable[index]->letter);
        while(contact) {
            printf("[   %s, %s  [%d]  %s  %s   ]\n\n", contact->contact.lastName, contact->contact.firstName, contact->contact.Age, contact->contact.occupation, contact->contact.phoneNumber);
            contact = contact->next;
        }
    }
}