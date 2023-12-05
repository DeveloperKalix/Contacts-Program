#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nationality.h"

#define MAX_ORGS 3
#define ORG_LENGTH 50

struct Contact {
    char firstName[25];
    char lastName[25];
    int Age;
    char occupation[50];
    char organizations[MAX_ORGS][ORG_LENGTH];
    char nationality[50]
};

int main() {
    
    struct Dictionary* Nationalities = (struct Dictionary *)calloc(1, sizeof(struct Dictionary));
    dictionaryInsertion(Nationalities, "Russian", "🇷🇺");
    free(Nationalities);
    return 0;
}