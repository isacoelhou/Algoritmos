#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_NOME 30
#define TAM_END 40
#define TAM_FONE 15

FILE *arquivo;
typedef struct
{
    char nome[TAM_NOME];
    char endereco[TAM_END];
    char telefone[TAM_FONE];
} registro;


int insereRegistro()
{
    registro a;
    fseek(arquivo, 0, SEEK_END);
    system("clear");

    printf("\nInserção de Registro\n\n");
    printf("Nome: ");
    getchar();
    gets(a.nome);
    printf("Endereço: ");
    gets(a.endereco);
    printf("Telefone: ");
    gets(a.telefone);

    fwrite(&a, sizeof(registro), 1, arquivo);

    printf("\nRegistro inserido! Tecle [ENTER]\n");
    getchar();
    return 0;
}

void bubblesort(FILE *F)
{
    int i, j, n;
    registro aux1, aux2;
    int sizer = sizeof(registro);

    fseek(F, 0, SEEK_END);
    n = ftell(F) / sizer;
    for (i = 1; i < n; i++)
    {
        for(j = n; j >= i; j--)
        {
            fseek(F, (j-1)*sizer, SEEK_SET);
            fread(&aux1, sizer, 1, F);
            fread(&aux2, sizer, 1, F);

            if(strcmp(aux1.nome, aux2.nome) > 0)
            {
                fseek(F, (j-1)*sizer, SEEK_SET);
                fwrite(&aux2, sizeof(registro), 1, F);
                fwrite(&aux1, sizeof(registro), 1, F);

            }
        }
    }
}

int listaRegistro()
{
    registro a;
    int n;

    fseek(arquivo, 0, SEEK_END);
    n = ftell(arquivo)/sizeof(registro);
    getchar();
    system("clear");

    bubblesort(arquivo);
    rewind(arquivo);

    while(1){
    fread(&a, sizeof(registro), 1, arquivo);

    if(!feof(arquivo))
    {
        printf("Registro:%lu/%d\n", ftell(arquivo)/sizeof(registro), n);
        printf("Nome: %s\nEndereço: %s\nTelefone: %s\n", a.nome, a.endereco, a.telefone);
        printf("\nTecle [ENTER], para o próximo registro\n");
        getchar();
    }
    else break;
    }
    return 0;
}

int buscaRegistro()
{
    registro a;
    char chave[TAM_NOME];
    int found = 0;

    getchar();
    rewind(arquivo);
    system("clear");

    printf("\tBusca por nome");
    printf("Buscar por: ");
    gets(chave);

    while(1)
    {
        fread(&a, sizeof(registro), 1, arquivo);
        if(!feof(arquivo))
        {
            if(!strncmp(a.nome, chave, strlen(chave)))
            {
                printf("Nome: %s \n", a.nome);
                printf("Endereço: %s \n", a.endereco);
                printf("Telefone: %s \n", a.telefone);
                printf("Tecle [ENTER]");
                getchar();
                found++;
            }
        }
        else break;
    }
    if(!found)
    {
        printf("Nome não encontrado.\n");
        printf("Tecle [ENTER]");
        getchar();
    }
    return 0;
}

int alteraRegistro()
{
    registro a;
    char chave[TAM_NOME];

    getchar();
    rewind(arquivo);
    system("clear");
    printf("\tMudança de dados\n");
    printf("Buscar por: \n");
    gets(chave);

    while(!feof(arquivo))
    {
        fread(&a, sizeof(registro), 1, arquivo);
        if (!feof(arquivo))
    {

    }
    }
}

int main()
{
    int opcao = -1;
    int (*pf[6])();

    pf[0] = insereRegistro;
    pf[1] = listaRegistro;
    pf[2] = buscaRegistro;
    pf[3] = alteraRegistro;
    pf[4] = NULL;
    pf[5] = NULL;
    pf[6] = NULL;

    if(!(arquivo = fopen("dados.dat", "rb+")))
    {
        printf("\nErro: não foi possível abrir o arquivo de dados!\n");
        printf("\nCriando um novo arquivo de dados...\n");
        arquivo = fopen("dados.dat", "wb");
        system("pause");
    }

    while(opcao)
    {
        system("clear");
        printf("\tAgenda\n\n");
        printf("Menu principal\n\n");
        printf("\t[0] Sair\n");
        printf("\t[1] Inserir registro\n");
        printf("\t[2] Listar registro\n");
        printf("\t[3] Buscar registro\n");
        printf("\t[4] Alterar registro\n");
        printf("\t[5] Apagar registro\n");
        printf("\nQual sua opção?");
        scanf("%d", &opcao);
        if ((opcao > 0) && (opcao <= 5))
        {
            (*pf[opcao-1])();
        }
    }

    if (fclose(arquivo))
    {
        printf("\nErro: não foi possível fechar seu arquivo de dados!/n");
        return 1;
    }

    return 0;
}