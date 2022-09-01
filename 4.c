#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *arquivo;
	char files[100], aux, tenho, substituo;
	
	printf("Qual arquivo deseja abrir? >>");
	scanf("%s", files);
	
	getchar();
	
	printf("Qual letra quer substituir? >> ");
	scanf("%c", &tenho);
	
	getchar();
	
	printf("\nQual letra sera a substituta? >> ");
	scanf("%c", &substituo);
	
	getchar();
	printf("\n");
	
	if((arquivo = fopen(files, "r+")) == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		exit(1);
	}
	
	while(1)
	{
		aux=fgetc(arquivo);
		if(!feof(arquivo))
		{
			if(aux==tenho)
			{
				fseek(arquivo, -1, SEEK_CUR);
				fputc(substituo, arquivo);
			}
		}
		else
			break;
	}

	fclose(arquivo);
	
	return 0;
}
