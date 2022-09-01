#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *dados;		
	char filename[50]; 	
	char s[101];
    char aux;
    int cont=0;
	
	printf("Nome do arquivo a ser aberto: ");
	scanf("%s", filename);
	

	if ((dados = fopen(filename, "w")) == NULL)
	{
		printf("Erro: O arquivo não pode ser aberto!");
		exit(1);
	}

	// lê os dados a serem gravados no arquivo
    cont = 6;
	while(cont--)
   {
      scanf("%[^'\n']s", s);
      getchar();
        fprintf(dados, "%s\n", s);
   }
      
   fclose(dados);
   
	// lê os dados gravados no arquivo
   if ((dados = fopen(filename, "r")) == NULL)
	{
		printf("Erro: O arquivo não pode ser aberto!");
		exit(1);
	}

   while (1)
   {      
     fscanf(dados, "%s", s);
      if (!feof(dados))
         printf("%s\n", s);
      else
         break;
   }
	
	// fecha o arquivo
	fclose(dados);
	return 0;
}