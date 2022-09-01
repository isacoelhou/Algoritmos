// Isadora Coelho
// Gabriel Lenser

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// função para a soma dos racionais
float f1(unsigned a)
{
if(a==1){
return (float)a;
}else{
return ((1/(float)a) + f1(a-1));
}
}

typedef struct
{
int num;
int den;
} racional;

typedef racional Tdata;

//tipo de dado para lista encadeada
typedef  struct TNode
{
    Tdata info;
    struct TNode *prev;
    struct TNode *next;
} TNode;

typedef struct TListDE
{
    TNode *first;
    TNode *last;
    short length;
} TListDE;

// Função de Inicialização da lista
void initList(TListDE *L)
{
    L->first = NULL;
    L->last = NULL;
    L->length = 0;
}

// Soma dos elementos da lista
float sumlist(TListDE L)
{
TNode *p = L.first;
Tdata s;


while(p)
{
s.num += (p->info.num*p->info.den) + (p->info.den*p->info.num);
}
}

// Função para inverter a lista

void invertlist (TListDE *L)
{

TNode *aux;
TNode *aux2;
L->last = L->first;

while (L->first)
{
aux2 = L->first->next;
L->first->next = aux;
L->first->prev = aux2;
aux = L->first;
L->first = aux2;
}

L->first = aux;

}
// Função para inserir um elemento a direita
short insertRight(Tdata x, TListDE *L)
{
    TNode *aux = (TNode*)malloc(sizeof(TNode));
    if (aux == NULL)
        return 1;
    else
    {
        aux->info = x;
        aux->next = NULL;                    // Não tem próximo
        aux->prev = L->last;                // O anterior é o antigo último

        if (L->last == NULL)                // Lista estava vazia
            L->first = L->last = aux;    // atualiza primeiro e último
        else                          // atualiza só o último
        {
            L->last->next = aux;            // liga o novo último nó
            L->last = aux;                    // atualiza o ponteiro para o novo último
        }
        L->length++;                        // atualiza o comprimento
        return 0;
    }
}

// Função para printar a lista
void printList(TListDE L)
{
  TNode *p = L.first;

  printf ("S = ");
  while (p)
    {
      printf ("%d/%d ", p->info.num, p->info.den);
      if (p->next)
    printf (" + ");
      p = p->next;
    }
  printf ("\n\n");
}

double soma(TListSE L)
{
    TNode *p = L.first;
    double y=0;

    while(p)
    {
        y += (double)p->info.num/p->info.den;
        p = p->next;
    }
    return y;
}

int main()
{
TListDE l1;
Tdata x;
x.num = 1;
x.den = 1;

double y=0;

y =  soma(L1);
initList(&l1);


for(int i=1; i<=19; i++)
{
x.num += 2;
x.den *= 2;
insertRight(x,&l1);
}


printList(l1);

printf("S = %.5lf\n ", y); // print da soma dos elementos
invertlist(&l1); // função para inverter a lista
printList(l1);

return 0;

}
