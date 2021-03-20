#include <stdio.h>
#include <stdlib.h>

//definisco la coda mazzo
typedef struct Mazzo{
    char C;
    char P;
    char D;
    char F;
    struct Mazzo*next;
}mazzo;


//funzione dequeue 
mazzo* dequeue(mazzo **head,mazzo **tail){
    mazzo *ret=*head;

	if(*head == NULL){
		return NULL;
	}
	else
		(*head)=ret->next;
	if(*head == NULL)
		*tail=NULL;
	return ret;
}
//funzione enqueue
void enqueue(mazzo **head, mazzo **tail,mazzo *element){
	if(*head==NULL){
		*head=element;
	}
	else {
        (*tail)->next=element;
    }
	
	*tail=element;
	element->next=NULL;
}




int main(){
    //inizializzo la testa, la coda, elemento di tipo mazzo e 
    mazzo *head;
    mazzo *tail;
    mazzo *element;

    //inizializzo testa e coda a NULL
    head=NULL;
    tail=NULL;

    //ciclo per quante sono le carte nel mazzo
    for (char i = 0; i < 52; i++)
    {
        //4 if che servono per mettere le carte ogni 13 volte(non ancora funzionante)
        if(i>=0 && i<13)
        {
            element->C=i+1;
            enqueue(&head,&tail,element);
        }
        else if (i>=13 && i<26)
        {
            element->P=i+1;
            enqueue(&head,&tail,element);
        }
        else if (i>=26 && i<39)
        {
            element->D=i+1;
            enqueue(&head,&tail,element);
        }
        else if (i>=39 && i<52)
        {
            element->F=i+1;
            enqueue(&head,&tail,element);
        }
    }
    return 0;
}