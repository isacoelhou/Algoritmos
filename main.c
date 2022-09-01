 //main
 #include <stdio.h>
 #include "t.h"

float Vet[50];

int main(void)
{
	IntVet A;
	int m;

	printf("Testando biblioteca t.h\n");
	initIntVet(&A);
	scanIntVet(&A);
   	printf("\n");
   	printVet(Vet, m);
  	sumVet(Vet, m);
 	printf("%f", media(Vet, m));
	return 0;
}
