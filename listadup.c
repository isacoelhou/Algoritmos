#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// define o tipo de dado a ser colocado na lista
typedef short Tdata;

//tipo de dado para lista encadeada
typedef  struct TNode
{
	Tdata info; // dado armazenado no nó
  struct TNode *prev;	// ponteiro para o nó anterior
	struct TNode *next;	// ponteiro para o próximo nó
} TNode;

typedef struct TListDE
{
	TNode *first;
	TNode *last;
	short length;
} TListDE;


//==============================================================================

//inicialização da lista
void initList(TListDE *L)
{
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
}

// destruição da lista
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

// verifica lista vazia
bool emptyList(TListDE L)
{
	return (L.length == 0);
}

// escreve a lista;
void printList(TListDE L, bool inverse)
{
  TNode *p;
  if (!inverse)
  {
    printf("First->");
    p = L.first;
    while (p)
    {
      printf("[%hd]->", p->info);
      p = p->next;
    }
    printf("[NULL]");
  }
	else
	{
		printf("Last->");
    p = L.last;

    while (p)
    {
      printf("[%hd]->", p->info);
      p = p->prev;
    }
    printf("[NULL]");
	}
  return;
}

// inserção pela esquerda
short insertLeft(Tdata x, TListDE *L)
{
	TNode *aux;
	aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL)	// falha na alocação
		return 1;	// sinaliza com erro, deixando a lista original intacta
	else
	{ // insere x na lista
		aux->info = x;					// Atribui x para o campo info.
		aux->next = L->first;		// Insere o elemento antes do atual primeiro.
		aux->prev = NULL;				// não tem anterior
		if (L->first != NULL)
			L->first->prev = aux;
		L->first = aux;				// Faz o ponteiro do primeiro apontar para o novo nó.
		if (L->last == NULL)			// lista estava vazia
			L->last = aux;				// primeiro elemento é também o último
		L->length++;					// incrementa o tamanho da lista
		return 0;						// fim normal
	}
}

// Inserção pela direita
short insertRight(Tdata x, TListDE *L)
{
	TNode *aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL)
		return 1;
	else
	{
		aux->info = x;
		aux->next = NULL;					// Não tem próximo
		aux->prev = L->last;				// O anterior é o antigo último

		if (L->last == NULL)				// Lista estava vazia
			L->first = L->last = aux;	// atualiza primeiro e último
		else                          // atualiza só o último
		{
			L->last->next = aux;			// liga o novo último nó
			L->last = aux;					// atualiza o ponteiro para o novo último
		}
		L->length++;						// atualiza o comprimento
		return 0;
	}}

	// remoção pela esquerda
void removeFirst(TListDE *L)
{
	TNode *aux = L->first;		// Guarda o nó a ser removido em aux
	L->first = L->first->next;	// Avança para o próximo nó
	free(aux)	;					// libera aux
	if (L->first == NULL)		// Lista ficou vazia
		L->last = NULL;			// Anula o last também
  else
  L->first->prev = NULL;
	L->length--;					// reduz o tamanho
}

// remoção pela direita

void removeLast(TListDE *L)
{
	TNode *aux = L->last;		// Guarda o nó a ser removido em aux
	L->last = L->last->prev;	// volta para o nó anterior
	free(aux)	;					// libera aux
	if (L->last == NULL)			// Lista ficou vazia
		L->first = NULL;			// Anula o first também
  else
    L->last->next = NULL;			// Anula o próximo do novo último
	L->length--;					// reduz o tamanho
}

//////////////////////////////////////////////////////////////////////////////

void invertList(TListDE *L)
{
	TNode *aux1 = NULL;
	TNode *aux2 = NULL;
	L->last=L->first;

	while(L->first != NULL)
	{
		  aux2=L->first->next;
    L->first->next = aux1;
		  aux1 = L->first;
	  	L->first->prev= aux2;
	  	L->first = aux2;
	}
		  L->first= aux1;
}

int insert(Tdata x, unsigned pos, TListDE *L)
{

	TNode *aux;

	if(pos==0){
		insertLeft(x, L);}
	else if(pos>=L->length){
		insertRight(x, L);}
	else
	{

		aux = (TNode*)malloc(sizeof(TNode));
		if (aux == NULL)
			return 1;
		else
		{
			TNode *aux2 = L->first;
			aux->info = x;

				for(unsigned i=0; i<pos; i++)
					aux2 = aux2->next;
					aux->next=aux2->next;
					aux2->next=aux;
					aux->next->prev = aux;
					aux->prev = aux2;
		}
	}
}

void removepos(unsigned pos, TListDE *L)
{
	TNode *aux= L->first;
	TNode *aux2;
	if (pos == 0)
		removeFirst(L);
  else if (pos >= L->length)
		removeLast(L);
	else
		{
			for(int i=0; i<pos-2; i++)
			aux=aux->next;
			aux2=aux->next->next;
			free(aux->next);
			aux->next=aux2;
			aux2->prev = aux;
			L->length--;
		}
}

unsigned contaoc(TListDE *L, Tdata x)
{
      TNode *aux = L->first;
      unsigned oc = 0;
      while(aux!=NULL)
     {
       if(aux->info == x)
       oc++;
       aux= aux->next;
     }
     return oc;
}

void concaten(TListDE *L,TListDE *L2)
{
	 TNode *aux = L->last;
	 TNode *aux2 = L2->first;
	 aux->next = aux2;
	 aux2->prev = aux;
}


void removex(TListDE *L, Tdata x)
{
     TNode *aux = L->first;
     TNode *aux2;

     if(L->first->info == x)
     		removeFirst(L);
     else if (L->last->info == x)
     		removeLast(L);
     else
     {
     while((aux->next!=NULL)&&(aux->next->info!=x))
		 	aux=aux->next;
	 		aux2=aux->next->next;
			free(aux->next);
			aux->next=aux2;
			aux2->prev = aux;
			L->length--;
     }
}

void RemoveX(int x, TListDE *L)
{
	TNode *aux = L->first;
	TNode *aux2;
	unsigned i=0;
	while(aux->next != NULL && aux != NULL)
    {
        if (aux->info == x && i == 0){
            removeFirst(L);
            aux=L->first;}
        else if (aux->next->info == x && i == L->length){
            removeLast(L);}
        else if (aux->next->info == x) {
					aux2=aux->next->next;
					free(aux->next);
					aux->next=aux2;
					aux2->prev = aux;
            L->length-=1;}
        else{
            aux = aux->next;
            i++;}
    }
}

int main()
{
	TListDE L1, L2;
	short a, b;
	TNode *n;

	printf("Inicializando a lista...\n");
	initList(&L1);
	initList(&L2);
	printf("Lista Inicializada!\n\n");

  if (emptyList(L1))
	printf("A lista está vazia!\n");

	insertLeft(1, &L1);
	insertLeft(1, &L1);
	insertLeft(1, &L2);
	insertLeft(1, &L2);
  printf("Inserindo 1 na lista pela esquerda...\n");
	if (insertLeft(1, &L1) == 0)
		printf("Inserção realizada com sucesso\n");
	else
		printf("Erro na inserção!\n");

  printf("Inserindo 2 na lista pela esquerda...\n");
	if (insertLeft(2, &L1) == 0)
		printf("Inserção realizada com sucesso\n");
	else
		printf("Erro na inserção!\n");

  printf("Inserindo 3 na lista pela direita...\n");
	if (insertRight(3, &L1) == 0)
		printf("Inserção realizada com sucesso\n");
	else
		printf("Erro na inserção!\n");

	printf("Inserindo 4 na lista pela direita...\n");
	if (insertRight(4, &L1) == 0)
		printf("Inserção realizada com sucesso\n");
	else
		printf("Erro na inserção!\n");

	printList(L1, false); //first to last
	printf("\n\n");

	printf("seu elemento ocorre %u vezes em L1\n",contaoc(&L1, 1));
	printList(L1, false);
	printf("\n");

	RemoveX(1,&L1);
	printList(L1, false);
	printf("\n");

	printf("Destruindo a lista...\n");
	deleteList(&L1);
  printf("Lista apagada!");

	return 0;
}
