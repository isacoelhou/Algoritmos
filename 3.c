#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main()
{
    FILE *arquivo, *gravado;
    char files[100], filesg[100], aux;
    int N[10], A[26];

    memset(N, 0, sizeof(int)*10);
    memset(A, 0, sizeof(int)*26);

    printf("Qual arquivo deseja abrir? >>");
    scanf("%s", files);

    printf("Qual arquivo deseja gravar? >>");
    scanf("%s", filesg);

    if((arquivo = fopen(files, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    if((gravado = fopen(filesg, "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    while(1)
    {

        fscanf(arquivo, "%c", &aux);
        if(!feof(arquivo))
        {            
            if(isdigit(aux))
                N[aux-48]++;
            else if(isalpha(aux))
                A[toupper(aux)-65]++;                
        }
        else
            break;

    }

    fclose(arquivo);

    fprintf(gravado, "caractere | N de ocorrencias\n");
    fprintf(gravado, "=======================================\n");
    for(int i=0; i<10; i++)
        fprintf(gravado, "%-10d|%5d\n", i, N[i]);
    for(int j=0; j<26; j++)
        fprintf(gravado, "%-10c|%5d\n", j+65, A[j]);
    fprintf(gravado, "=======================================\n");    
    fclose(gravado);
    return 0;

}