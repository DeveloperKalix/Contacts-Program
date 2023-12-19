#ifndef NATIONALITY_H
#define NATIONALITY_H

#define MAX_ENTRIES 200
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 50

struct KVP {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct KVP* next;
};

struct Dictionary {
    char title[40];
    struct KVP* head;
    struct KVP* tail;
    int insertions;
};

struct Dictionary* createDictionary(char* title);
int dictionarySize(struct Dictionary* dict);
void printDictionary(struct Dictionary* dict);
struct KVP* locateKVP(const struct Dictionary* dict, const char* key);
char* Retrieve(const struct Dictionary* dict, const char* key);
void dictionaryInsertion(struct Dictionary* dict, const char* key, char* value);
char* retrieveNationality(struct Dictionary* dict, const char *key); 
void deleteDictionary(struct Dictionary* dict);

#endif