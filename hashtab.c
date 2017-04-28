#include "hashtab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


unsigned int hashtab_hash_djb(char *key)
{
    unsigned int hash = 5381;
    int c;

    while (c = *key++)
        hash = ((hash << 5) + hash) + c;

    return hash % 100;
}

unsigned int hashtab_hash(char *key)
{
	unsigned int value = 0;

	for (int i = 0; key[i] != '\0'; i++) {
		if (key[i] == '\n') {
			continue;
		}	
		value += key[i];		
	}

	return value % 100;
}

void hashtab_init(Node **hashtab)
{
	for (int i = 0; i < 100; i++) {
		hashtab[i] = NULL;
	}
}

void hashtab_add(Node **hashtab, char *key, int value)
{
	Node *node,*k;

	//int index = hashtab_hash(key);
	int index = hashtab_hash_djb(key);

	node = malloc(sizeof(*node));

	if (node) {
		node->value = value;
		node->key = key;
		node->next=hashtab[index];
		hashtab[index] = node;
		
}
}

Node *hashtab_lookup(Node **hashtab, char *key)
{
	int index;
	Node *node;

	index = hashtab_hash(key);

	for (node = hashtab[index]; node != NULL; node = node->next) {
		if (strcmp(node->key, key) == 0) {
			return node;
		}
	}
	return NULL;
}

void hashtab_delete(Node **hashtab, char *key)
{
	int index;
	Node *p, *prev = NULL;

	index = hashtab_hash(key);

	for (p = hashtab[index]; p != NULL; p = p->next) {
		if (strcmp(p->key, key) == 0) {
			if (prev == NULL) {
				hashtab[index] = p->next;
			} else {
				prev->next = p->next;
			}
			free(p);
			return;
		}
		prev = p;
	}
}
