#ifndef BSTREE_H
#define BSTREE_H

typedef struct binary_search_tree {
    char *key;
    int value;
    struct binary_search_tree *left, *right;
} bstree;

bstree * bstree_create(char *key, int value);
bstree *bstree_add(bstree *tree, char *key, int value);
bstree *bstree_lookup(bstree *tree, char *key);
bstree *bstree_min(bstree *tree);
bstree *bstree_max(bstree *tree);


#endif
