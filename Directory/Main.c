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
    //printDictionary(Nationalities);
    char character = 'D';
    //unsigned int num = hashFunction(&character);
    //printf("%d\n", num);
    char* pn = "2010653987";
    char* formattedPN = malloc(sizeof(char) * 15);
    formattedPN = formatPhoneNumber(pn, 0);
    //printf("DIAL: %s\n", formattedPN);
    if(formattedPN == NULL) {
        printf("This is not a valid phone number.\n");
    }
    else
    {
        printf("DIAL: %s\n", formattedPN);
    }
    free(formattedPN);
    // char* test = Retrieve(Nationalities, "Jamaican");
    // printf("YES! %s\n", test);
    AddressBook* Contacts = createAddressBook("My Contacts");
    int age = 30;
    Contact_Node* contact1 = createContact("John", "Jimson", "2010653987", &age, "Engineer", Retrieve(Nationalities, "Angolan"), Nationalities);
    age = 25;
    Contact_Node* contact2 = createContact("Alice", "Smith", "9876543210", &age, "Doctor", Retrieve(Nationalities,"Armenian"), Nationalities);
    age = 15;
    Contact_Node* contact3 = createContact("Emma", "Johnson", "2345678901", &age, "Teacher", Retrieve(Nationalities,"Jamaican"), Nationalities);
    age = 65;
    Contact_Node* contact4 = createContact("Michael", "Jordan", "8765432109", &age, "Artist", Retrieve(Nationalities,"Turkish"), Nationalities);
    age = 69;
    Contact_Node* contact5 = createContact("Sophia", "Tyler", "3456789012", &age, "Programmer", Retrieve(Nationalities,"Greek"), Nationalities);
    age = 72;
    Contact_Node* contact6 = createContact("Emily", "Taylor", "2345678901", &age, "Engineer", Retrieve(Nationalities,"Polish"), Nationalities);
    age = 41;
    Contact_Node* contact7 = createContact("Daniel", "Jackson", "7654321098", &age, "Teacher", Retrieve(Nationalities,"German"), Nationalities);
    age = 22;
    // Contact_Node* contact8 = {"Olivia", "Wilson", "5432109876", 29, "Doctor", *Retrieve(Nationalities,"American Samoan")};
    // Contact_Node* contact9 = {"Matthew", "Moore", "8901234567", 38, "Artist", *Retrieve(Nationalities,"American Samoan")};
    // Contact_Node* contact10 = {"Ella", "Garcia", "6789012345", 23, "Programmer", *Retrieve(Nationalities,"Jamaican")};
    // Contact_Node* contact11 = {"Liam", "Martinez", "0123456789", 31, "Engineer", *Retrieve(Nationalities,"Turkish")};
    // Contact_Node* contact12 = {"Ava", "Lopez", "4567890123", 26, "Doctor", *Retrieve(Nationalities,"French")};
    // Contact_Node* contact13 = {"Mark", "Hernandez", "9876543210", 34, "Teacher", *Retrieve(Nationalities,"Portuguese")};
    // Contact_Node* contact14 = {"Isabella", "Gonzalez", "3210987654", 30, "Artist", *Retrieve(Nationalities,"Danish")};
    // Contact_Node* contact15 = {"Oliver", "Rivera", "6543210987", 24, "Programmer", *Retrieve(Nationalities,"Russian")};
    insertContact(Contacts,contact1);
    insertContact(Contacts,contact2);
    insertContact(Contacts,contact3);
    insertContact(Contacts,contact4);
    insertContact(Contacts,contact5);
    insertContact(Contacts,contact6);
    insertContact(Contacts,contact7);
    printAddressBook(Contacts);
    removeContact(Contacts, "Emily", "Taylor");
    removeAddressBook(Contacts);
    deleteDictionary(Nationalities);
    //insertContact(AddressBook* AB, Contact_Node* individual)
    
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
    dictionaryInsertion(Nationalities, "American", "🇺🇸");
    dictionaryInsertion(Nationalities, "Albanian", "🇦🇱");
    dictionaryInsertion(Nationalities, "Croatian", "🇭🇷");
    dictionaryInsertion(Nationalities, "Georgian", "🇬🇪");
    dictionaryInsertion(Nationalities, "Austrian", "🇦🇹");
    dictionaryInsertion(Nationalities, "Serbian", "🇷🇸");
    dictionaryInsertion(Nationalities, "Chinese", "🇨🇳");
    dictionaryInsertion(Nationalities, "Japanese", "🇯🇵");
    dictionaryInsertion(Nationalities, "Korean", "🇨🇳");
    dictionaryInsertion(Nationalities, "Argentinian", "🇦🇷");
    dictionaryInsertion(Nationalities, "Brazilian", "🇧🇷");
    dictionaryInsertion(Nationalities, "Peruvian", "🇵🇪");
    dictionaryInsertion(Nationalities, "Colombian", "🇨🇴");
    dictionaryInsertion(Nationalities, "Libyan", "🇱🇾");
    dictionaryInsertion(Nationalities, "Syrian", "🇸🇾");
    dictionaryInsertion(Nationalities, "American Samoan", "🇦🇸");
    dictionaryInsertion(Nationalities, "Indian", "🇮🇳");
    dictionaryInsertion(Nationalities, "Nepalese", "🇳🇵");
    dictionaryInsertion(Nationalities, "Pakistani", "🇵🇰");
    dictionaryInsertion(Nationalities, "Bulgarian", "🇧🇬");
    dictionaryInsertion(Nationalities, "Swedish", "🇸🇪");
    dictionaryInsertion(Nationalities, "Norwegian", "🇳🇴");
    dictionaryInsertion(Nationalities, "Finnish", "🇫🇮");
    dictionaryInsertion(Nationalities, "Spanish", "🇪🇸");
    dictionaryInsertion(Nationalities, "Portuguese", "🇵🇹");
    dictionaryInsertion(Nationalities, "Moroccan", "🇲🇦");
    dictionaryInsertion(Nationalities, "Ethiopian", "🇪🇹");
    dictionaryInsertion(Nationalities, "Ugandan", "🇺🇬");
    dictionaryInsertion(Nationalities, "South Africa", "🇿🇦");
    dictionaryInsertion(Nationalities, "Iraqi", "🇮🇶");
    dictionaryInsertion(Nationalities, "Persian", "🇮🇷");
    dictionaryInsertion(Nationalities, "Zambia", "🇿🇲");
    dictionaryInsertion(Nationalities, "Zimbabwean", "🇿🇼");
    dictionaryInsertion(Nationalities, "Mozambican", "🇿🇦");
    dictionaryInsertion(Nationalities, "Turkish", "🇹🇷");
    dictionaryInsertion(Nationalities, "Greek", "🇬🇷");
    dictionaryInsertion(Nationalities, "Italian", "🇮🇹");
    dictionaryInsertion(Nationalities, "Romanian", "🇷🇴");
    dictionaryInsertion(Nationalities, "German", "🇩🇪");
    dictionaryInsertion(Nationalities, "Polish", "🇵🇱");
    dictionaryInsertion(Nationalities, "Vietnamese", "🇻🇳");
    dictionaryInsertion(Nationalities, "Slovakian", "🇸🇰");
    dictionaryInsertion(Nationalities, "Czech", "🇨🇿");
    dictionaryInsertion(Nationalities, "Swiss", "🇨🇭");
    dictionaryInsertion(Nationalities, "Laosian", "🇱🇦");
    dictionaryInsertion(Nationalities, "Cambodian", "🇰🇭");
    dictionaryInsertion(Nationalities, "Azerbaijani", "🇦🇿");
    dictionaryInsertion(Nationalities, "Irish", "🇮🇪");
    dictionaryInsertion(Nationalities, "Australian", "🇦🇺");
    dictionaryInsertion(Nationalities, "Jamaican", "🇯🇲");
    dictionaryInsertion(Nationalities, "Nicaraguan", "🇳🇮");
    dictionaryInsertion(Nationalities, "Chilean", "🇨🇱");
}