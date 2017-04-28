#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include <string.h>


bstree *bstree_create(char *key, int value)
{
    bstree *tree;
    tree = malloc(sizeof(*tree));
    if (tree != NULL) {
        tree->key = key;
        tree->value = value;
        tree->left = NULL;
        tree->right = NULL;
    }
    return tree;
}

bstree *bstree_add(bstree *tree, char *key, int value)
{
    if (!tree) {
        return bstree_create(key, value);
    }
    if (*key < *tree->key) {
    
        tree->left =  bstree_add(tree->left, key, value);
    }
    else {
        
        tree->right = bstree_add(tree->right, key, value);
    }

    return tree;
}


bstree * bstree_lookup(bstree *tree, char *key)
{
    while (tree) {
        if (key == tree->key) {
            //printf("Found: %s    %d\n", tree->key, tree->value);
            return tree;
        }
        else if (*key < *tree->key)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return tree;
}


bstree *bstree_min(bstree *tree)
{
    if (!tree)
        return NULL;

    while (tree->left)
        tree = tree->left;
    return tree;
}



bstree *bstree_max(bstree *tree)
{
    if (!tree)
        return NULL;

    while (tree->right)
        tree = tree->right;
    return tree;
}
