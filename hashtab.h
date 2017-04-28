#ifndef HASHTAB_H
#define HASHTAB_H

#define HASH_MUL 31
#define HASH_SIZE 71

typedef struct listnode {
    char *key;
    int value;
    struct listnode *next;
} Node;

Node *hashtab[HASH_SIZE];
//unsigned int hashtab_hash_djb(char *key)
unsigned int hashtab_hash(char *key);
void hashtab_init(Node **hashtab);
void hashtab_add(Node **hashtab, char *key, int value);
Node *hashtab_lookup(Node **hashtab, char *key);
void hashtab_delete(Node **hashtab, char *key);


#endif
