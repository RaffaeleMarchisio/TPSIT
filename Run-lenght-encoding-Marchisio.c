/*RAFFAELE MARCHISIO 4B-ROB*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main(){
    //inizializzo le variabili
    char str[MAX];
    char str2[MAX];
    int n=0;
    int risp=0;
    do  //ciclo finche la risposta non è uguale a 3 cioè ad "uscire"
    {
        //faccio scegliere all'utente cosa vuole fare
        printf("1-encoding\n2-decoding\n3-uscire\nselezionare una delle seguenti opzione(scrivere numero):"); 
        scanf("%d",&risp);

        if (risp==1)
        {
            printf("inserire una stringa:");      //chiedo in input una stringa
            scanf("%s",str);

            for(int i = 0; i<strlen(str); i++)    //faccio il ciclo per codificare
            {
                if (str[i]==str[i+1])           //controllo se il carattere è uguale al suo successivo
                {
                    n++;
                }
                else if(str[i]!=str[i+1] ||str[i+1]=='\0') //controllo se il carattere è diverso al suo successivo 
                {                                           //o se è uguale al carattere di fine stringa
                    n++;
                    printf("%d%c",n,str[i]);                //stampo numero + carattere
                    n=0;
                }
            }
            printf("\n");
        }
        else if(risp==2)
        {
            printf("inserire una stringa:");
            scanf("%s",str);
            for(int k=0; k<strlen(str); k++)
            {
                if(str[k]>= '0' && str[k]<='9'){
                    n=str[k]-'0';
                }
                else
                {
                    for(int j=0; j<n; j++)
                        printf("%c",str[k]);
                    
                    n=0;
                }
            }
            printf("\n");
        }
    }while (risp!=3);
    return 0;
}
