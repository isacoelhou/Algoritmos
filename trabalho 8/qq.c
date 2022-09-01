#include <stdio.h>
#include <stdlib.h>

typedef struct Racional
{
    int num;
    int den;
}TRacional;

// define o tipo de dado a ser colocado na lista
typedef TRacional Tdata;

//tipo de dado para lista encadeada
typedef  struct TNode
{
    Tdata info; // dado armazenado no nó
    struct TNode *next;    // ponteiro para o próximo nó
} TNode;

typedef struct TListSE
{
    TNode *first;
    TNode *last;
    short length;
} TListSE;


// Inicialização da lista
void initList(TListSE *L)
{
    L->first = NULL;
    L->last = NULL;
    L->length = 0;
}

// destruição da lista
void deleteList(TListSE *L)
{
    TNode *p = L->first;
    while (p)
    {
        L->first = L->first->next;
        free(p);
        L->length--;
        p = L->first;
    }
    L->last = NULL;
}


// Inserção pela direita
short insertRight(Tdata x, TListSE *L)
{
    TNode *aux = (TNode*)malloc(sizeof(TNode));
    if (aux ==NULL)
        return 1;
    else
    {
        aux->info = x;
        aux->next = NULL;

        if (L->last == NULL)
            L->first = L->last = aux;
        else
        {
            L->last->next = aux;
            L->last = aux;
        }
        L->length++;
        return 0;
    }
}

void printList(TListSE L)
{
    TNode *aux = L.first;

    printf("S = ");
    while (aux) //aux percorre todos os elementos da lista
    {
        printf("[%d/%d]", aux->info.num, aux->info.den);
        if (aux->next)
            printf("+");
        aux = aux->next;
    }
    printf("\n");
}

void Printinv(TListSE L)
{
    TNode *aux = L.first;

    printf("S = ");
    for(int i=L.length ; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
        if(j == i-1)
           printf("[%d/%d]", aux->info.num, aux->info.den);
        else
            aux = aux->next;
        }
        if (i > 1)
            printf("+");
      	aux = L.first;
    }
}


double soma(TListSE L)
{
    TNode *aux = L.first;
    double x=0;

    while(aux)
    {
        x += (double)aux->info.num/aux->info.den;
        aux = aux->next;
    }
    return x;
}


int main()
{
    TListSE L1;
    Tdata x;
    double y;

    initList(&L1);

    for(int a = 1; a <= 100; a++)
    {
        x.num=1;
        x.den= a;
        insertRight(x,&L1);
    }
    printList(L1);
    printf("\n");
    Printinv(L1);
    printf("\n");

    deleteList(&L1);
    printf("S = %.5f\n", soma(L1));


    return 0;
}
