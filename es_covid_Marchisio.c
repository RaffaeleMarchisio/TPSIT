#include <stdio.h>
#include <stdlib.h>

int main()
{
    //inizializzo tutte le variabili
    float R=0;            
    int N=0;               
    float *p;
    int g=0, i=0;

    printf("inserire il numero di studenti:");  //chiedo in input il numero di studenti
    scanf("%d",&N);

    printf("inserire R:");
    scanf("%f",&R);

    p=(float*)malloc(N*sizeof(int));      //alloco dinamicamente un'array
    p[0]=1;                              //inizializzo la prima cella del mio array a 1

    for(int n_contagiati=1, i=1; n_contagiati<N; i++)
    {
        p[i]=p[i-1]*R;              //trovo il numero di contagiati
        n_contagiati=p[i];              //metto il numero di contagiati nella variabile n_contagiati

        printf("Giorno %d numero contagiati %d\n",i,n_contagiati); //faccio un analisi giornaliera della situazione
        g=i;
    }
    free(p);    //libero il puntatore

    printf("per contagiare tutti ci ha messo %d giorni",g); //stampo quanto ci ha messo in giorni a contagiare tutti
    return 0;
}