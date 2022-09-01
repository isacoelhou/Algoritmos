// files4.c
// exemplo de escrita em arquivos binários

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *dados;			// ponteiro para arquivo de dados
	char filename[50]; 	// nome do arquivo a ser aberto
	char s;		// variável com os dados a ser gravada no arquivo
	
	printf("Nome do arquivo a ser aberto: ");
	scanf("%s", filename);
	

	if ((dados = fopen(filename, "w")) == NULL)
	{
		printf("Erro: O arquivo não pode ser aberto!");
		exit(1);
	}

	// lê os dados a serem gravados no arquivo
	while(1)
   {
      s = getchar();
      if(s !='0')
         fprintf(dados, "%c", s);
      else
      break;
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
      s = fgetc(dados);
      if (!feof(dados))
         printf("%c", s);
      else
         break;
   }
	
	// fecha o arquivo
	fclose(dados);
	return 0;
}