#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nationality.h"
#include "Contact.h"

#define MAX_LENGTH 50

void initializeNationalities(struct Dictionary* Nationalities);

int main() {
    
    FILE *file = fopen("contacts.txt", "r");
    if(file == NULL) {
        perror("No Contacts found.");
        return EXIT_FAILURE;
    }

    char dictTitle[100] = "Nationalities List";
    struct Dictionary* Nationalities = createDictionary(dictTitle);
    AddressBook* Contacts = createAddressBook("My Contacts");
    initializeNationalities(Nationalities);
    char firstName[MAX_LENGTH +1], lastName[MAX_LENGTH +1], theAge[3], phonenumber[10+1], occupation[50+1], nationality[MAX_LENGTH +1] = ""; 
    int intage = 0;
    char singleContact[175];
    while(fgets(singleContact, sizeof(singleContact), file) != NULL) {
        char* token;
        int count = 0;
        occupation[0] = '\0';
        token = strtok(singleContact, " ");
        //strcpy(firstName, token);
        char temp[25] = "";
        while(token != NULL) {
            switch(count) {
                case(0):
                  strcpy(firstName, token);
                  token = strtok(NULL, " ");
                  break;
                case(1):
                  strcpy(lastName, token);
                  token = strtok(NULL, " ");
                  break;
                case(2):
                  strcpy(theAge, token);
                  intage = atoi(theAge);
                  token = strtok(NULL, " ");
                  break;
                case(3):
                  strcpy(nationality, token);
                  token = strtok(NULL, " ");
                  break;
                case(4):
                 strcpy(phonenumber, token);
                 token = strtok(NULL, " ");
                  break;
                default:
                  strcpy(temp, token);
                  strcat(occupation, temp);
                  strcat(occupation, " ");
                  token = strtok(NULL, " ");
                  break;
            }
            strcpy(temp, "");
            count++;
            
        }
        //printf("%s! %s! %d! %s! %s! %s!\n", firstName, lastName, intage, phonenumber, nationality, occupation);
        Contact_Node* new_Contact = createContact(firstName, lastName, phonenumber, &intage, occupation, Retrieve(Nationalities, nationality), Nationalities);
        insertContact(Contacts, new_Contact);
        
    }
    
    //printDictionary(Nationalities);
    char character = 'D';
    char* pn = "2010653987";
    char* formattedPN = malloc(sizeof(char) * 15);
    formattedPN = formatPhoneNumber(pn, 0);
    if(formattedPN == NULL) {
        printf("This is not a valid phone number.\n");
    }
    free(formattedPN);
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
    fclose(file);
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
    dictionaryInsertion(Nationalities, "Zambian", "🇿🇲");
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