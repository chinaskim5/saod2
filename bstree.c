#include "bstree.h"



bstree *bstree_create(char *key,char *value){

    bstree *node=(bstree *)malloc(sizeof(node));
    if (node != NULL){
	node->key=key;
	node->value=value;
	node->left=NULL;
	node->right=NULL;
    }
    return node;
}

bstree *bstree_add(bstree *tree,char *key, char *value){
    bstree *parent,*node;
    
    if (tree == NULL)
	return 0;
    
    for(parent=tree; tree != NULL; ){
	parent = tree;
	if ( key < tree->key)
	    tree = tree->left;
	else if (key > tree->key)
	    tree = tree->right;
	else
	    return 0;
    }
    node = bstree_create(key, value);
    if (key < parent->key)
	parent->left= node;
    else
	parent->right = node;

}

bstree * bstree_lookup(bstree *tree, char *key){

    while (tree !=NULL){
	if (key == tree->key){
	    return tree;
	} else if (*key < *tree->key){
	    tree= tree->left;
	} else {
	    tree= tree->right;
	}
    }
    return tree;
}

bstree *bstree_max(bstree *tree){

    if (tree == NULL)
	return NULL;
	
    while (tree->right !=NULL)
	tree = tree->right;
    return tree;
}

bstree *bstree_min(bstree *tree){

    if (tree == NULL)
	return NULL;

    while (tree->left != NULL)
	tree = tree->left;

    return tree;
}








