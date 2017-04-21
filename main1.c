#include "hashtab.h"
#define size 51203




int main ()
{
listnode *node;
char words[size][25];
int i;

FILE *in=fopen("book.txt","r");
for ( i=0; i < size; i++)
{
    fscanf(in,"%s",words[i]);
}
fclose(in);

for (i=0; i<size;i++)
{
    hashtab_add(hashtab,words[i],i);
}

}
