#include <stdio.h>
#include <stdlib.h>
struct El
{
    int valore;
    struct El* next;
};

void push(struct El** head,int val)
{
    struct El *punt_app=*head;

    if(*head==NULL)
    {
        (*head)=(struct El*)malloc(sizeof(struct El*));
        (*head)->valore = val;
        (*head)->next=NULL;
    }
    else
    {
        while (punt_app->next!=NULL)
        {
            punt_app=punt_app->next;
        }
        punt_app->next=(struct El*)malloc(sizeof(struct El*));
        punt_app->next->valore=val;
        punt_app->next->next=NULL;
    }
    
}
void stampalista(struct El *head){
    if(head==NULL)
    {
        printf("fine lista");
    }
    else{
        printf("%d\n",head->valore);
        stampalista(head->next);
    }
}
int main()
{
    int n;
    struct El* lista;
    struct El* l;
    lista=NULL; /* si inizializza il primo elemento della lista(lista) a NULL */
    l=lista;

    do
    {
        printf("Inserisci un numero naturale o -1 per terminare:");
        scanf("%d",&n);
        if (n>=0)
        {   
            push(&lista,n);
        }
    } while (n>=0);

    l=lista; /* pongo il puntatore d'appoggio(l) uguale al primo elemento della lista(lista), 
                visto che per stampare la lista serve solo il primo elemento*/
    printf("numeri inseriti: \n");
    stampalista(l);
    printf("\n");
    return 0;
}