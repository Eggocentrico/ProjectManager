#include <math.h>

#define hashTableSize(int *table) floor(sizeof(table) / sizeof(int))

int mkHash (char *key) {
	int hash = 0x00001010;
	const int constant = 0x01010111;
	for (int i = 0; i < floor(sizeof(key) / sizeof(char)); i++) {
		hash = (hash << key[i]) + constant;
	} 
	return hash;
}

void insertKey (int *hashTable, char* key, int value) {
	int hash = mkHash(key);
	hashTable[hash % (int)hashTableSize(hashTable)] = value;
}

int getKey (int *hashTable, char* key) {
	int hash = mkHash(key);
	return hashTable[hash % (int)hashTableSize(hashTable)];
}



