// implementação da biblioteca
#include <stdio.h>
#include <string.h>
#include "t.h"


float Vet[50];

void initIntVet(IntVet *V)
{
	memset(V,0,sizeof(IntVet));
	return;
}

void scanIntVet(IntVet *V)
{
	printf("Tamanho >>> ");
	scanf("%d", &V->size);
	for(int i = 0; i < V->size; i++)
	{
		printf("A[%d] >> ", i);
		scanf("%d", &V->data[i]);
	}
}

void printVet(float *V, int n)
{
    printf("V = [");
    for(int i = 0; i < n; i++)
    {
        if (i == n -1)
        printf("%.1f]\n", Vet[i]);
        else
        printf("%.1f, ", Vet[i]);
    }
}

// soma os elementos do vetor
float sumVet(float *V, int n)
{
    float sum = 0;
     for(int i = 0; i < n; i++)
    {
        sum += Vet[i];
    }
    printf("%.1f\n", sum);
    return sum;
}

float media(float *V, int n)
{
    float m;
    float sum = sumVet(V,n);
    m = (sumVet(V,n)/n);
    return m;
 }
