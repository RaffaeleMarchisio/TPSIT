#include <stdio.h>
#include <string.h>
#define SIZE 1000

int main()
{
    FILE *fp;
    char righe[SIZE];
    char *p;
    char *str;
    int cont_a,contt,cont_g,cont_c;

    fp=fopen("rna.txt","r");
    if (fp!=NULL)
    {
        while (fgets(righe,SIZE,fp))
        {
            p=strtok(righe," ");
            p=strtok(NULL," ");
            str=strdup(p);
            for (int i = 0; i < strlen(str); i++)
            {
                if (str[i]=='a')
                {
                    cont_a++;
                }
                else if (str[i]=='t')
                {
                    contt++;
                }
                else if (str[i]=='g')
                {
                    cont_g++;
                }
                else if (str[i]=='c')
                {
                    cont_c++;
                }
            }
            p=strtok(NULL," ");
            str=strdup(p);
            for (int i = 0; i < strlen(str); i++)
            {
                if (str[i]=='a')
                {
                    cont_a++;
                }
                else if (str[i]=='t')
                {
                    contt++;
                }
                else if (str[i]=='g')
                {
                    cont_g++;
                }
                else if (str[i]=='c')
                {
                    cont_c++;
                }
            }
            p=strtok(NULL," ");
            str=strdup(p);
            for (int i = 0; i < strlen(str); i++)
            {
                if (str[i]=='a')
                {
                    cont_a++;
                }
                else if (str[i]=='t')
                {
                    contt++;
                }
                else if (str[i]=='g')
                {
                    cont_g++;
                }
                else if (str[i]=='c')
                {
                    cont_c++;
                }
            }
        }
        
    }
    fclose(fp);

    printf("%d ",cont_a);
    printf("%d ",cont_c);
    printf("%d ",cont_g);
    printf("%d ",contt);
    return 0;
}