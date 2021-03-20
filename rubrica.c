#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_CONTATTI 1024
#define MAX 1000

typedef struct contact{
    int id;
    char nome[64];
    char numero[16];
}contatto;

typedef struct Rubrica{
    int num_inseriti;
    contatto db[MAX_NUM_CONTATTI];
}rubrica;

char *trova_numero(rubrica *r, char nome[MAX])
{
    int i=0;
    contatto *p;
    for (int i = 0; i < MAX_NUM_CONTATTI; i++)
    {
        if (i==r->num_inseriti)
            break;
        p=&r->db[i];

        if (strcmp(p->nome,nome)==0)
        {
            return p->numero;
        }
        return NULL;
    }
    
}

int inserisci(rubrica *r,char nome[MAX],char numero[MAX])
{
    printf("10000");
    contatto *p;
    if (r->num_inseriti==MAX_NUM_CONTATTI)
    {
        printf("Rubrica piena");
        return -1;
    }
    p=&r->db[r->num_inseriti];

    strcpy(p->nome,nome);
    strcpy(p->numero,numero);
    p->id=r->num_inseriti++;
    r->num_inseriti++;
    return 0;
}

void stampa_rubrica(rubrica *r){
    int i;
    contatto *p;

    printf("\nStampa rubrica: %d contatti\n",r->num_inseriti);

    for (int i = 0; i < MAX_NUM_CONTATTI; i++)
    {
        if (i==r->num_inseriti)
            break;
        p=&r->db[i];

        printf("%s,%s\n",p->nome,p->numero);
    }
}

int main()
{
    rubrica *r;
    char nome[MAX];
    int numero;
    char *num;
    int risp;
    int lung;

    do{

        printf("1-INSERISCI\n2-STAMPARE_RUBRICA\n3-TROVARE_NUMERO\nScegliere tra una delle seguenti opzioni:");
        scanf("%d",&risp);
    
        if (risp==1)
        {
            printf("inserire il nome della persona:");
            scanf("%s",nome);

            printf("inserire il numero:");
            scanf("%d",&numero);

            sprintf((char*)num, "%d", numero);
            
            printf("%s",(char*)num);
        
            //inserisci(r,nome,num);
        }
        else if (risp==2)
        {
            stampa_rubrica(r);
        }
        else if (risp==3)
        {
            //printf("inserire il nome della persona di cui vuoi trovare il numero:");
            //scanf("%s",nome);

            //strcpy(numero,trova_numero(r,nome));

            //printf("il numero di %s e' %s",numero);
        }
    
    }while(risp<3 || risp==0);

    return 0;
}