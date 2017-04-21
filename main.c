#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"
#include <time.h>
#include <sys/time.h>
#define size 51203

double wtime()
{
    struct timeval t;
    gettimeofday(&t,NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max-min) + min;
}




int main()
{
    char words[size][25];
    int i;
    bstree *tree, *node;
    double t,g;
    srand((unsigned)time(NULL));
    FILE *in = fopen("book.txt","r");
    for (i=0;i<size;i++)
    {
	fscanf(in,"%s",words[i]);
    }
    fclose(in);
    tree = bstree_create(words[0],0);
    FILE *out;
    out=fopen("yo1.txt","w");
    for(i=1;i<size;i++)
    {
	tree=bstree_add(tree,words[i],i);
	if (i % 2000 == 0 )
	{
	    t = wtime();
	    node = bstree_lookup (tree, words[getrand(0,(i-1))]);
	    fprintf(out,"%d \t %.6f\n",i/2000,wtime()-t);
	}
    }
    printf("YOO\n");
}
