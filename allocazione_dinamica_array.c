/*
creazione di un array utilizzando la funzione malloc
*/

#include <stdlib.h>

int main(){
    int *puntatore;
    int n=0;

    scanf("inserire dimensione dell'array: %d", &n);
    
    puntatore=(int *)malloc(sizeof(int)*n);  
    /* si fa un cast di quello che ritorna la malloc perchè 
    la malloc ritorna un puntatore di tipo void* e quindi si fa un cast per renderlo int* */


    for(int i=0; i<n; i++){   //acquisizione numeri
        scanf("inserire un numero: %d", (puntatore+i));
    }

    for(int i=0; i<n; i++){  //stampaggio dati
        printf("%d\n", *(puntatore+i));
    }


    free(puntatore);
    /* dopo avere utilizzato quell'area di memoria, 
    nel programma, si deve liberare l'area di memoria di utilizzata; utilizzando la funzione free */
    
    return 0;
}