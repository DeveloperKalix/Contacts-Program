#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nationality.h"
#include "Contact.h"



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
    dictionaryInsertion(Nationalities, "Ukrainian", "🇺🇦");
    dictionaryInsertion(Nationalities, "Belgian", "🇧🇪");
    dictionaryInsertion(Nationalities, "Turkish", "🇹🇷");
    dictionaryInsertion(Nationalities, "Israeli", "🇮🇱");
    printDictionary(Nationalities);
    deleteDictionary(Nationalities);
    
    return 0;
}