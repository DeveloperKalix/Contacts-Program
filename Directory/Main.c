#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nationality.h"
#include "Contact.h"

void initializeNationalities(struct Dictionary* Nationalities);

int main() {
    
    char dictTitle[100] = "Nationalities List";
    struct Dictionary* Nationalities = createDictionary(dictTitle);
    initializeNationalities(Nationalities);
    printDictionary(Nationalities);
    deleteDictionary(Nationalities);
    char character = 'D';
    //unsigned int num = hashFunction(&character);
    //printf("%d\n", num);
    char* pn = "2010653987";
    char* formattedPN = malloc(sizeof(char) * 15);
    formattedPN = formatPhoneNumber(formattedPN, pn, 0);
    if(formattedPN == NULL) {
        printf("This is not a valid phone number.\n");
    }
    else
    {
        printf("DIAL: %s\n", formattedPN);
    }
    free(formattedPN);
    return 0;
}

void initializeNationalities(struct Dictionary* Nationalities) {
    dictionaryInsertion(Nationalities, "Angolan", "🇦🇴");
    dictionaryInsertion(Nationalities, "Armenian", "🇦🇲");
    dictionaryInsertion(Nationalities, "Azerbaijani", "🇦🇿");
    dictionaryInsertion(Nationalities, "Danish", "🇩🇰");
    dictionaryInsertion(Nationalities, "Canadian", "🇨🇦");
    dictionaryInsertion(Nationalities, "Cambodian", "🇰🇭");
    dictionaryInsertion(Nationalities, "French", "🇫🇷");
    dictionaryInsertion(Nationalities, "Russian", "🇷🇺");
    dictionaryInsertion(Nationalities, "Ukrainian", "🇺🇦");
    dictionaryInsertion(Nationalities, "Belgian", "🇧🇪");
    dictionaryInsertion(Nationalities, "Turkish", "🇹🇷");
    dictionaryInsertion(Nationalities, "Israeli", "🇮🇱");
}