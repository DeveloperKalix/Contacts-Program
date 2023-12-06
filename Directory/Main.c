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
    char nationality[1]
};

int main() {
    
    char dictTitle[100] = "Nationalities List";
    struct Dictionary* Nationalities = createDictionary(dictTitle);
    dictionaryInsertion(Nationalities, "Angolan", "🇦🇴");
    dictionaryInsertion(Nationalities, "Armenian", "🇦🇲");
    dictionaryInsertion(Nationalities, "Azerbaijani", "🇦🇿");
    dictionaryInsertion(Nationalities, "Danish", "🇩🇰");
    dictionaryInsertion(Nationalities, "Canadian", "🇨🇦");
    dictionaryInsertion(Nationalities, "Cambodian", "🇰🇭");
    dictionaryInsertion(Nationalities, "French", "🇫🇷");
    dictionaryInsertion(Nationalities, "Russian", "🇷🇺");
    dictionaryInsertion(Nationalities, "Ukraine", "🇺🇦");
    dictionaryInsertion(Nationalities, "Belgian", "🇧🇪");
    dictionaryInsertion(Nationalities, "Turkish", "🇹🇷");
    dictionaryInsertion(Nationalities, "Israel", "🇮🇱");
    printDictionary(Nationalities);
    deleteDictionary(Nationalities);
    return 0;
}