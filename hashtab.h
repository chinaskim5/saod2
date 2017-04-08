#ifndef "HASHTAB_H"
#define "HASHTAB_H"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define HASHTAB_SIZE 10
#define HASHTAB_MUL 5

typedef struct hash_tabl{
	char *key;
	int value;
	
	struct hash_tabl *next;
}listnode; 

listnode *hashtab[HASHTAB_SIZE];
unsigned int hashtab_hash(char *key);

void hashtab_init(listnode **hashtab);

void hashtab_add(listnode **hashtab, char *key, int value);

listnode *hashtab_lookup(listnode **hashtab, char *key);

void hashtab_delete(listnode **hashtab, char *key);



#endif
