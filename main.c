#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"
#include <time.h>
#define size 51203






int main()
{
    char words[size][25];
    int i;
    bstree *tree, *node;
    FILE *in = fopen("book.txt","r");
    for (i=0;i<size;i++)
    {
	fscanf(in,"%s",words[i]);
    }
    fclose(in);
    tree = bstree_create(words[0],0);
    for(i=1;i<size;i++)
    {
	tree=bstree_add(tree,words[i],i);
    }
    printf("YOO\n");
}
