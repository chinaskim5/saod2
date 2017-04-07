#include "bstree.h"

int main ()
{
    bstree *tree, *node;
    char tr[][99]={"first","second","third"};
    
    tree = bstree_create(tr[0],"Yo");
    bstree_add(tree, tr[1],"YOO");
    bstree_add(tree, tr[2],"YoYo");
    
    node = bstree_lookup(tree,tr[2]);
    printf("Value = %s %s\n",node->key, node->value);
    
    node = bstree_min(tree);
    printf("Min value= %s %s\n",node->key, node->value);
    
    return 0;
    
}

