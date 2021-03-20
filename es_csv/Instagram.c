#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Dati{
    char mese[MAX];
    int id_post;
    int giorno;
    int like;
}dati;

int main(){
    //inizializzo
    FILE *fp;
    dati *d;
    char input_mese[MAX];
    int cont=0;
    char righe[MAX];
    char *s;
    int n=0;

    d=(dati*)malloc(29*sizeof(dati));

    fp=fopen("instagram.csv","r");    //apro il file in lettura
    if (fp!=NULL)
    {
        while(fgets(righe,MAX,fp))    //ciclo finche non finscono le righe      
        {
            if (cont!=0)             
            {
                //carico le tutti i valori delle variabili
                s=strtok(righe,",");            
                strcpy((d+cont)->mese,s);           
                s=strtok(NULL,",");
                (d+cont)->giorno=atoi(s);
                s=strtok(NULL,",");
                (d+cont)->id_post=atoi(s);
                s=strtok(NULL,",");
                (d+cont)->like=atoi(s);
            }
            cont++;
        }
    }
    else
    {
        printf("errore");
    }
 
    printf("inserire il nome del mese:");               //chiedo in input il nome del mese
    fgets(input_mese,MAX,stdin);   

    
    //non funziona ancora bene
    for (int i = 1; i < 29; i++)
    {
        if (strcmp((d+i)->mese,input_mese))            //controllo se mese nel e uguale al mese          
        {
            printf("numero_post:%d numero_like:%d",(d+i)->id_post,(d+i)->like);
        }
    }
    free(d);

    return 0;
}