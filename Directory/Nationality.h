#ifndef NATIONALITY_H
#define NATIONALITY_H

#define MAX_ENTRIES 50
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 50

struct KVP {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
}

struct Dictionary {
    struct KVP entries[MAX_ENTRIES];
}

void dictionaryInsertion(struct Dictionary* dict, const char* key, char* value);
char* retrieveNationality(struct Dictionary* dict, const char *key); 
void deleteDictionary(struct Dictionary* dict)