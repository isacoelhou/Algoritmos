// Leonardo Calsavara e Isadora Coelho
// Questão 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *entrada, *saida;		
	char in[56], out[56];
    char aux;
    int n;

	printf("Qual seu arquivo de entrada?\n");
	scanf("%s", in);
	printf("Qual seu arquivo de saída?\n");
	scanf("%s", out);

	if ((entrada = fopen(in, "r")) == NULL)
	{
		printf("Erro: O arquivo não pode ser aberto!");
		exit(1);
	}

    fscanf(entrada, "%d", &n);
	fclose(entrada);

	if ((saida = fopen(out, "w")) == NULL)
	{
		printf("Erro: O arquivo não pode ser aberto!");
		exit(1);
	}


	for(int i = 1; i <= n; i++)
	{
		if (n%i == 0)
		fprintf(saida, "%d\n", i);
	}

	fclose(saida);
    return 0;
}