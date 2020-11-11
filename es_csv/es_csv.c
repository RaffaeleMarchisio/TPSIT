#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define NSONG 1000
#define BSIZE 1000

typedef struct scanzone
{
    int numero;
    char titolo[MAX];
    char artista[MAX];
}Canzone;

int main()
{
    Canzone *playlist;
    FILE *fp;
    char riga[BSIZE];
    int cont=0,lung=0;
    char *field;
    int dim=10;
    int x=0,j,temp;
    int n[MAX];

    playlist=(Canzone*)malloc(10*sizeof(Canzone));

    fp=fopen("canzoni.csv","r");
    if (fp!=NULL)
    {
        while (fgets(riga,BSIZE,fp))
        {
            field=strtok(riga,",");
            (playlist+cont)->numero= atoi(field);
            field=strtok(NULL,",");
            strcpy((playlist+cont)->titolo,field);
            field=strtok(NULL,",");
            strcpy((playlist+cont)->artista,field);

            cont++;
        }
        
    }
    else
    {
        return -1;
    }
    
    for(int i=0;i<dim;i++){
        *(n+i)=i;
    }
    srand (time(NULL));
    for(int i=0;i<dim;i++){
        j=(rand()%9)+0;
        temp=*(n+i);
        *(n+i)=*(n+j);
        *(n+j)=temp;
    }
    for(int i=0;i<dim;i++){
        printf("%d %s %s",(playlist+*(n+i))->numero, (playlist+*(n+i))->titolo, (playlist+*(n+i))->artista);
        if((playlist+*(n+i))->numero==9)
        {
        	printf("\n");
        }
    }

    return 0;
}
