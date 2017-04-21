#include "hashtab.h"
#define size 51203
#include <sys/time.h>
#include <time.h>


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


int main ()
{
srand((unsigned)time(NULL));
listnode *node;
char words[size][25];
int i;
double t,g;
FILE *in = fopen("book.txt","r");
for ( i=0; i < size; i++)
{
    fscanf(in,"%s",words[i]);
}
fclose(in);
FILE *out;
out = fopen("yo2.txt","w");
for (i=0; i<size;i++)
{
    hashtab_add(hashtab,words[i],i);
    if (i % 2000 == 0 )
    {
	t=wtime();
	node = hashtab_lookup(hashtab,words[getrand(0,(i-1))]);
	fprintf(out,"%d \t %.6f\n",i/2000,wtime()-t);
    }
}


}
