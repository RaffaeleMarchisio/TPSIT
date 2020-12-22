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

typedef struct nodo{
    Canzone valore;
    struct nodo *next;
}Nodo;

typedef Nodo* Lista;

void pushCanzone(Lista* head, Canzone c){
    Nodo* puntatore_app= *head;

    if(*head == NULL)
    {
        (*head)=(Nodo*)malloc(sizeof(Nodo));
        (*head)->valore.numero = c.numero;
        strcpy((*head)->valore.titolo, c.titolo);
        strcpy((*head)->valore.artista, c.artista);
        (*head)->next=NULL;
    }
    else
    {
        while (puntatore_app->next!=NULL)
        {
            puntatore_app=puntatore_app->next;
        }
        //qui siamo arrivati all'ultimo elemento della lista
        puntatore_app->next=(Nodo*)malloc(sizeof(Nodo));
        puntatore_app->next->valore.numero = c.numero;
        strcpy(puntatore_app->next->valore.titolo, c.titolo);
        strcpy(puntatore_app->next->valore.artista, c.artista);
        puntatore_app->next->next=NULL;
    }
}

int main()
{
    Canzone punt;
    Lista primo = NULL;
    Nodo *l;
    FILE *fp;
    char riga[BSIZE];
    int cont=0,lung=0;
    char *field;
    int dim=10;
    int n[dim];
    int j = 0;
    int temp = 0;

    fp=fopen("canzoni.csv","r");
    if (fp!=NULL)
    {
        while (fgets(riga,BSIZE,fp))
        {            
            field=strtok(riga,",");
            punt.numero=atoi(field);
            field=strtok(NULL,",");
            strcpy(punt.titolo,field);
            field=strtok(NULL,",");
            strcpy(punt.artista,field);
            pushCanzone(&primo,punt);
        }
    }
    else
    {
        return -1;
    }

    for(int i=0;i<dim;i++){
        *(n+i)=i;
    }
    
    srand(time(NULL));
    for(int i=0; i < dim; i++)
    {
        j = rand() % dim;
        temp = *(n + i);
        *(n + i) = *(n + j);
        *(n + j) = temp;

        /*for(int k = 0; k < dim; k++)
            printf("%d ", n[k]);
        printf("\n");*/
    }
    
    for(int w = 0; w < dim; w++)
    {
        l = primo;
        for(int x = 0; x < *(n + w); x++)
        {
            l = l->next;
        }

        printf("%d %s %s", l->valore.numero,l->valore.titolo,l->valore.artista);

        if(l->valore.numero == dim - 1)
            printf("\n");
    }

    return 0;
}






/*metodologia file.csv
fgets(nome variabile in cui salva,lunghezza,puntatore)
permette di leggere il file riga dopo riga
strdup prende una stringa e fa una copia*/
