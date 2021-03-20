#include <stdio.h>
#include <stdlib.h>
struct El
{
    int valore;
    struct El* next;
};

int main()
{
    int n;
    struct El* lista;
    struct El* l;
    lista=NULL; /* si inizializza il primo elemento della lista(lista) a NULL */

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d",&n);
        if (n>=0)
        {   
            if (lista==NULL) /* controllo se il primo elemento della lista(lista) è vuoto */
            {
                /* se è vuoto allora lo alloco e pongo il puntatore d'appoggio(l) uguale al primo elemento della lista(lista) */
                lista = (struct El*) malloc(sizeof(struct El));
                l = lista;
            }
            else /* altrimenti se il primo elemento della lista non è vuoto */
            {
            /* alloco il prossimo elemento della lista e faccio puntare il puntatore d'appoggio(l) all'elemento appena allocato */
                l->next = (struct El*) malloc(sizeof(struct El));
                l = l->next;
            }
            l->valore = n; /* pongo il valore puntato dal puntatore d'appoggio(l) uguale al valore inserito dall'utente(n) */
            l->next = NULL; /* pongo il prossimo elemento(l->next) uguale a NULL */
        }
    } while (n>=0);

    l=lista; /* pongo il puntatore d'appoggio(l) uguale al primo elemento della lista(lista), 
                visto che per stampare la lista serve solo il primo elemento*/
    printf("numeri inseriti: ");
    while (l!=NULL)
    {
        printf("%d - %p \n",l->valore, l->next);
        l=l->next; /* faccio puntare il puntatore d'appoggio(l) al prossimo elemento della lista */
    }
    printf("\n");
    return 0;
}