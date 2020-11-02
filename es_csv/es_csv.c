#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    Canzone playlist[NSONG];
    FILE *fp;
    char riga[BSIZE];
    int cont=0;
    char *field;

    fp=fopen("canzoni.csv","r");
    if (fp!=NULL)
    {
        while (fgets(riga,BSIZE,fp))
        {
            field=strtok(riga,",");
            playlist[cont].numero = atoi(field);
            field=strtok(NULL,",");
            playlist[cont].titolo =strdup(field);
            field=strtok(NULL,",");
            playlist[cont].artista =strdup(field);

            cont++;
        }
        
    }
    else
    {
        return -1;
    }
    for (int i = 0; i < 50; i++)
    {
        printf("%s",playlist->titolo[i]);
    }
    return 0;
}



/*metodologia file.csv
fgets(nome variabile in cui salva,lunghezza,puntatore)
permette di leggere il file riga dopo riga
strdup prende una stringa e fa una copia*/