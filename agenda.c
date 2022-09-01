#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM_nome 30
#define TAM_end 40
#define TAM_fone 15


typedef struct
{
	char nome[TAM_nome];
	char endereco[TAM_end];
	char telefone[TAM_fone];
}registro;

FILE *arquivo;

//=====================================================
//FUNCOES
//=====================================================

//funcao para inserir

int insereRegistro()
{
	registro a;
	fseek(arquivo, 0, SEEK_END);
	system("clear");
	printf("\tInsercao de registro\n\n");
	printf("Nome: ");
	getchar();
	gets(a.nome);
	printf("Endereco: ");
	gets(a.endereco);
	printf("Telefone: ");
	gets(a.telefone);
	fwrite(&a, sizeof(registro), 1, arquivo);
	printf("\n\tRegistro inserido! Tecle [ENTER]\n");
	getchar();
	return 0;
}
//funcao para ordenar por nomes
void bubblesort(FILE *f)
{
	int i, j, n;
	registro aux1, aux2;
	int sizer = sizeof(registro);
	
	//calcula o numero de registro
	fseek(f, 0, SEEK_END);
	n = ftell(f) / sizer;
	for(i=1; i<n; i++)
	{
		for(j = n-1; j>=i; j--)
		{
			//posiciona para fazer a leitura
			fseek(f, (j-1)*sizer, SEEK_SET);
			// le os dados dos registros adjacentes para a memoria
			fread(&aux1, sizer, 1, f);
			fread(&aux2, sizer, 1, f);
			//compara os nomes 
			if(strcmp(aux1.nome, aux2.nome) > 0)
			{
				fseek(f, (j-1)*sizer, SEEK_SET);
				fwrite(&aux2, sizeof(registro), 1, f);
				fwrite(&aux1, sizeof(registro), 1, f);
			}
		}
	}
}
//funcao para listar os registros da agenda	
int listaRegistro()
{
	registro a;
	int n;
	
	fseek(arquivo, 0, SEEK_END);
	n = ftell(arquivo)/sizeof(registro);//calcula o numero de registros
	getchar();
	system("clear");
	
	//ordena primeiro
	bubblesort(arquivo);
	rewind(arquivo);
	
	while(1)
	{
		fread(&a, sizeof(registro), 1, arquivo);
		if(!feof(arquivo))
		{
			printf("Registro: %lu/%d\n", ftell(arquivo)/sizeof(registro), n);
			printf("Nome; %s\nEndereco: %s\nTelefone: %s\n", a.nome, a.endereco, a.telefone);
			printf("\nTecle [ENTER] para o proximo registro\n");
			getchar();
		}
		else
			break;
	}
	return 0;
}

//busca o dado que o usari queira
int buscaRegistro()
{
	registro a;
	char chave[TAM_nome];
	int found = 0;
	
	getchar();
	rewind(arquivo);
	system("clear");
	printf("\tBusca por nome\n");
	printf("\nBusca por: \n");
	gets(chave);
	
	while(1)
	{
		fread(&a, sizeof(registro), 1, arquivo);
		if(!feof(arquivo))
		{
			if(!strncmp(a.nome, chave, strlen(chave)))
			{
				printf("Nome: %s\n", a.nome);
				printf("Endereço: %s\n", a.endereco);
				printf("Telefone: %s\n", a.telefone);
				printf("tecle [ENTER]");
				getchar();
				found = 1;
			}
		}
		else
			break;
	}
	
	if(!found)
	{
		printf("Nome nao encontrado.\n");
		printf("Tecle [ENTER]");
		getchar();
	}
	return 0;
}

//alteracao de dados no arquivo
int alteraRegistro()
{
	registro a;
	char chave[TAM_nome];
	
	getchar();
	rewind(arquivo);
	system("clear");
	printf("\tAlteraco de dados\n");
	printf("Busca por: ");
	gets(chave);
	
	while(!feof(arquivo))
	{
		fread(&a, sizeof(registro), 1, arquivo);
		if(!feof(arquivo))
		{
			if(!strcmp(a.nome, chave))
			{
				printf("Endereço: %s\n", a.endereco);
				printf("Telefone: %s\n", a.telefone);
				printf("\tAlteraco de dados\n");
				printf("Qual novo nome?>> ");
				gets(a.nome);
				fflush(stdin);
				printf("Novo Endereço: ");
				gets(a.endereco);
				fflush(stdin);
				printf("Novo Telefone: ");
				gets(a.telefone);
				fflush(stdin);
				fseek(arquivo, -sizeof(registro), 1);
				fwrite(&a, sizeof(registro), 1, arquivo);
				printf("Tecle [ENTER]");
				getchar();
				return 0;
			}
		}
	}
	printf("Nome não encontrado.\n");
	printf("Tecle [ENTER]");
	getchar();
	return 0;
}
		
	
int main()
{
	int opcao = -1;
	int (*pf[6])(); //vetor de ponteiros de funcao para as funcoes serem escolhidas pelo menu
	
	//preenche o vetor de funcao
	
	pf[0] = insereRegistro;
	pf[1] = listaRegistro;
	pf[2] = buscaRegistro;
	pf[3] = alteraRegistro;
	pf[4] = NULL;
	
	//abre o arquivo de dados
	
	if(!(arquivo = fopen("dados.dat", "rb+")))
	{
		printf("nao foi possivel abrir o arquivo\n");
		printf("\nCriando novo arquivo de dados...\n");
		arquivo = fopen("dados.dat", "wb+");
		system("pause");
	}
	
	//Exibicao do menu
	while(opcao)
	{
		system("clear");
		printf("\tAgenta\n\n");
		printf("Menu principal\n\n");
		printf("\t[0] Sair\n");
		printf("\t[1] Inserir registro\n");
		printf("\t[2] Listar registro\n");
		printf("\t[3] Buscar registo\n");
		printf("\t[4] Alterar registro\n");
		printf("\t[5] Apagar registo\n");
		printf("\nQual sua opcao? >> ");
		
		scanf("%d", &opcao);
		
		if((opcao>0) && (opcao<=5))
		{
			(*pf[opcao - 1])();
		}
	}
	
	if(fclose(arquivo))
	{
		printf("\nErro: nâo foi possivel fechar o arquivo de dados\n");
		return -1;
	}
	return 0;
}
