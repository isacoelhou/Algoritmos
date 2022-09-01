#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int *dados; // dados armazenados
  unsigned n; // tamanho do vetor
} TVetDin;


void realocaVetDin(TVetDin *V, unsigned newSize, int data)
{
  V->dados = (int*)realloc(V->dados, newSize*sizeof(int)); //procura espaço na memória para alocação
  if (!V->dados)
  {
    printf("Erro: Memória insuficiente!\n");
    exit(1);
  }
  V->n = newSize; //cria novo tamanho para o vetor
  V->dados[newSize] = data; //adiciona o valor desejado

  return;
}

//função para imprimir
void printVetDin(TVetDin V)
{
  printf("[");
  for (unsigned i = 0; i < V.n; i++)
  {
    printf("%d", V.dados[i]);
    if (i < V.n - 1)
      printf(", ");
  }
  printf("]");
  return;
}

//somar elementos do vetor
float sumVet(TVetDin *V, int n) //n = tamanho do vetor
{
    float sum = 0;
     for(int i = 0; i < n; i++)
    {
        sum += V->dados[i];
    }
    return sum;
}

int acima(TVetDin *V, float media, int i)
{
    int m;
    for(int j = 0; j <= i; j++)
    {
      if (V->dados[j] > media) //compara o elemento com a média
      m++;
    }
    return m;
}

int abaixo(TVetDin *V, float media, int i)
{
    int m = 0;
    for(int j = 0; j <= i; j++)
    {
      if (V->dados[j] < media) //compara o elemento com a média
      m++;
    }
    return m-1;
}


int main()
{
    TVetDin A;
    int idade, i = 0;
    float media;

   while(scanf("%d", &idade) && idade>0)
    {
        realocaVetDin(&A, i, idade);
        i++;
    }
     media = sumVet(&A, i)/(i);
     printf("Média = %.2f\n", media);
     printf("Acima = %d\n", acima(&A, media, i));
     printf("Abaixo = %d\n", abaixo(&A, media, i));


}
