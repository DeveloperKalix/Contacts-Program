#include "Nationality.h"
#include <stdio.h>
#include <string.h>

void dictionaryInsertion(struct Dictionary* dict, const char *key, char *value) 
{
    char printThis[20];
    char printThat[20];
    strcpy(printThis, key);  // Copy the key into the Dictionary's key
    strcpy(printThat, value);  // Copy the value into the Dictionary's value
    printf("%s %s\n", printThis, printThat); 
};