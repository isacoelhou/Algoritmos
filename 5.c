#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE *arquivo;
	FILE *in, *out;
	char origem[256], destino[256];
	char c;
	
	if(argc!= 3)
	{
		printf("Erro, número incorreto de parâmetros :(\n");
		exit(1);
	}

	strcpy(origem, argv[1]);


    in = (arquivo = fopen(origem, "rb"));
	if(!in)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

	strcpy(destino, argv[2]);


    out =(arquivo = fopen(destino, "wb"));
	if (!out)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }


	while(1)
	{
		fread(&c, 1, 1, in);
		if(!feof(in))
			fwrite(&c, 1, 1, out);
		else 
			break;
	}

		fclose(in);
		fclose(out);

	}