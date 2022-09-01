#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char* argv[])
{
	FILE *criptografado;
	FILE *descriptografado;
	char filecripto[256], filedescripto[256], aux;
	int chave;
	
	if(argc != 3)
	{
		printf("parametros incorretos\n");
		exit(1);
	}
	
	scanf("%d", &chave);
	
	strcpy(filecripto, argv[1]);
	
	criptografado = fopen(filecripto, "rb");
	
	if(!criptografado)
	{
		printf("Erro ao abrir o arquivo1\n");
		exit(1);
	}
	
	fseek(criptografado, -chave, SEEK_END);
	
	strcpy(filedescripto, argv[2]);
	
	descriptografado = fopen(filedescripto, "wb");
	
	if(!descriptografado)
	{
		printf("Erro ao abrir o arquivo2\n");
		exit(1);
	}
	
	while(1)
	{
		fread(&aux, 1, 1, criptografado);
		if(!feof(criptografado))
			fwrite(&aux, 1, 1, descriptografado);
		else
		break;
	}
	
	fclose(criptografado);
	fclose(descriptografado);
	return 0;
}
	
	
	
	
