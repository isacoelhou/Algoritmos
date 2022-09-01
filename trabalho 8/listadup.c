#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef int Tdata;
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
	int length;
} TListDE;


void initList(TListDE *L)
{
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
}


void deleteList(TListDE *L)
{
	TNode *p = L->first;
	while (p)
	{
		L->first = L->first->next;
		free(p);
		p = L->first;
	}
	L->last = NULL;
  L->length = 0;
}



void printList(TListDE L, bool inverse)
{
  TNode *p;

  if (!inverse)
  {
    p = L.first;

    while (p)
    {
       if(p->next==NULL)
         printf("%d\n", p->info);
       else
         printf("%d ", p->info);
      p = p->next;
    }
  }
  return;
}
// Inserção pela direita
int insertRight(Tdata x, TListDE *L)
{
	TNode *aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL)
		return 1;
	else
	{
		aux->info = x;
		aux->next = NULL;
		aux->prev = L->last;

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
Tdata fib(TListDE L, int f)
{
	TNode *aux = L.last;
	Tdata s = 0;

	while (f)
	{
		s += aux->info;
		aux = aux->prev;
      f--;
	}
	return s;
}

int main()
{
   TListDE L1;

   int f;

   scanf("%d", &f);

   initList(&L1);

   if(f==1)
   {
      insertRight(0, &L1);
      printList(L1, false);
   }
   else if(f==2)
   {
      insertRight(0, &L1);
      insertRight(1, &L1);
      printList(L1, false);
   }
   else
   {
      insertRight(0, &L1);
      insertRight(1, &L1);
      for(int i=3; i<=f; i++)
      {
         insertRight(fib(L1,2), &L1);
      }
      printList(L1, false);
   }

   deleteList(&L1);

   return 0;
}
