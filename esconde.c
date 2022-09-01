#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char* argv[])
{
	FILE *arquOrigem;
	FILE *texto;
	FILE *arqDestino;
	char filein[256], filetexto[256], fileout[256], aux;
	int cont=0;
	
	
	if(argc != 4)
	{
		printf("numero de parametros incorreto\n");
		exit(1);
	}
	
	strcpy(filein, argv[1]);
	
	arquOrigem = fopen(filein, "rb");
	
	if(!arquOrigem)
	{
		printf("Erro ao abrir o arquivo1\n");
		exit(1);
	}
	
	
	strcpy(filetexto, argv[2]);
	
	texto = fopen(filetexto, "rb");
	
	if(!texto)
	{
		printf("Erro ao abrir o arquivo2\n");
		exit(2);
	}
	
	strcpy(fileout, argv[3]);
	
	arqDestino = fopen(fileout, "wb");
	
	if(!arqDestino)
	{
		printf("Erro ao abrir o arquivo3\n");
		exit(2);
	}
	
	while(1)
	{
		fread(&aux, 1, 1, arquOrigem);
		if(!feof(arquOrigem))
			fwrite(&aux, 1, 1, arqDestino);
		else
			break;
	}
	
	while(1)
	{
		fread(&aux, 1, 1, texto);
		if(!feof(texto))
		{	fwrite(&aux, 1, 1, arqDestino);
			cont++;
		}
		else
			break;
	}
	printf("a chave de acesso e>> %d\n", cont);
	fclose(arquOrigem);
	fclose(arqDestino);
	fclose(texto);
	return 0;
}
			
			
			
			
			
			
			
			
			
			
