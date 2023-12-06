#include "Nationality.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Dictionary* createDictionary(char* title) {
    struct Dictionary* dictionary = malloc(sizeof(struct Dictionary));
    strcpy(dictionary->title, title);
    printf("%s\n", dictionary->title);
    dictionary->head = NULL;
    dictionary->tail = NULL;
    dictionary->insertions = 0;
    return dictionary;
}

void deleteDictionary(struct Dictionary* dict) {
    struct KVP* ptr, *nextPtr;
    ptr = dict->head;
    while(ptr) {
        nextPtr = ptr->next;
        free(ptr);
        ptr = nextPtr;
    }
    free((void *) dict);
}

int dictionarySize(struct Dictionary* dict) {
    return dict->insertions;
}

struct KVP* locateKVP(const struct Dictionary* dict, const char* key) {
    struct KVP* inspector;
    inspector = dict->head;
    while(inspector) {
        if(strcmp(inspector->key, key) == 0) {
            return inspector;
        }
        else {
            inspector = inspector->next;
        }
    }
    return NULL;
}
char* Retrieve(const struct Dictionary* dict, const char* key) {
    if(locateKVP(dict, key)) {
        return locateKVP(dict, key)->value;
    }
    return NULL;
}

void printDictionary(struct Dictionary* dict) {
    struct KVP* printer = dict->head;
    while(printer) {
        printf("Nationality: %s\n", printer->key);
        printer = printer->next;
    }
}


void dictionaryInsertion(struct Dictionary* dict, const char *key, char *value) 
{
    struct KVP* Nationality = (struct KVP *)calloc(1, sizeof(struct KVP));
    strcpy(Nationality->key, key);
    strcpy(Nationality->value, value);
    if(dict->head == NULL) {
        dict->head = Nationality;
    }
    else if(dict->head && dict->tail == NULL)
    {
        int comparison = strcmp(dict->head->key, Nationality->key);
        if(comparison < 0) {
            dict->tail = Nationality;
        }
        else {
            dict->tail = dict->head;
            dict->head = Nationality;
        }
        dict->head->next = dict->tail;
    }
    else
    {
        if(dictionarySize(dict) < MAX_ENTRIES) {
            
            int checkLast = strcmp(Nationality->key, dict->head->key);
            if(checkLast > 0) {
                dict->tail->next = Nationality;
                dict->tail = Nationality;
            }
            else
            {
                struct KVP* DelayedPointer = (struct KVP *)calloc(1, sizeof(struct KVP));
                struct KVP* Temp = DelayedPointer;
                DelayedPointer->next = dict->head;
                struct KVP* Pointer = dict->head->next;
                while(Pointer) {
                    int comparison = strcmp(Nationality->key, DelayedPointer->key);
                    if(comparison > 0) {
                        Pointer = Pointer->next;
                        DelayedPointer = DelayedPointer->next;
                    }
                    else
                    {
                        Nationality->next = Pointer;
                        DelayedPointer->next = Nationality;
                        break;
                    }
                }
                free(Temp);
            }

            
        }
        
    }
    

    dict->insertions++;
};