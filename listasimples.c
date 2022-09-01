// Exemplos de algoritmos com listas encadeadas

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
	struct TNode *next;	// ponteiro para o próximo nó
} TNode;

typedef struct TListSE
{
	TNode *first;
	TNode *last;
	short length;
} TListSE;


// Funções sobre listas encadeadas

void printList(TListSE *L)
{
	TNode *p = L->first;

	printf("[");
	while (p)
	{
		printf("%hd", p->info);
		if (p->next)
			printf(", ");
		p = p->next;
	}
	printf("]");
}

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

// verifica lista vazia
bool emptyList(TListSE L)
{
	return (L.length == 0);
}

//remive last
void removeLast(TListSE *L)
{
	TNode *aux = L->first;

	if (L->first == L->last)		// há apenas um elemento na lista
	{
		free(L->first);					// libera o nó first
		L->last = L->first =NULL;	// anula tudo
	}
	else
	{	// tem mais de um na lista
		while (aux->next->next != NULL)		// procura pelo penúltimo
			aux = aux->next;
		L->last = aux;								// penúltimo é novo último
		free(aux->next);							// libera o último
		L->last->next = NULL;			// anula o nó depois do último
	}
	L->length--;
}


// inserção pela esquerda
short insertLeft(Tdata x, TListSE *L)
{
	TNode *aux;
	aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL)	// falha na alocação
		return 1;	// sinaliza com erro, deixando a lista original intacta
	else
	{ // insere x na lista
		aux->info = x;					// atribui x para o campo info
		aux->next = L->first;		// insere o elemento antes do atual primeiro
		L->first = aux;					// Faz o ponteiro do primeiro apontar para o novo nó
		if (L->last == NULL)		// lista estava vazia
			L->last = aux;				// primeiro elemento é também o último
		L->length++;						// incrementa o tamanho da lista
		return 0;								// fim normal
	}
}

void removeFirst(TListSE *L)
{
	TNode *aux = L->first;	// guarda o nó a ser removido em aux
	L->first = L->first->next;	// avança para o próximo nó
	free(aux)	;									// libera aux
	if (L->first == NULL)		// Lista ficou vazia
		L->last = NULL;			// Anula o last também
	L->length--;						// reduz o tamanho
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

		if (L->last == NULL)		// lista está vazia
			L->first = L->last = aux; // atualiza primeiro e último
		else                            // atualiza só o último
		{
			L->last->next = aux;
			L->last = aux;
		}
		L->length++;
		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////
// função para inverter a lista

void invertList(TListSE *L)
{
	TNode *aux1 = NULL;
	TNode *aux2 = NULL;
	L->last=L->first;

	while(L->first != NULL)
	{
		aux2=L->first->next;
    L->first->next = aux1;
		aux1 = L->first;
		L->first = aux2;
	}
		L->first= aux1;
}

short insereList(TListSE *L, Tdata x, unsigned pos)
{
    TNode *aux;

    if(pos==0){
  		insertLeft(x, L);}
    else if(pos >= L->length)
    	insertRight(x, L);
    else
    {
      aux = (TNode*)malloc(sizeof(TNode));
    if (aux == NULL)
        exit (1);
    else{
        TNode *aux2 = L->first;
        aux->info = x;

     for(unsigned i = 0; i<pos-2; i++)
         aux2 = aux2->next;
         aux->next = aux2->next;
         aux2->next = aux;
    }}}


void removelist(unsigned pos, TListSE *L)
{
	TNode *aux = L->first;
	TNode *aux2;

	if(pos==0)
	{removeFirst(L);}
	else	if(pos==L->length){
		removeLast(L);}
	else{
	for(unsigned i=0; i<pos-1; i++)
			aux=aux->next;

			aux2=aux->next->next;
			free(aux->next);
			aux->next=aux2;}
	L->length--;
}


void Printinv(TListSE L)
{
    TNode *aux = L.first;

    printf("L1 = [");
    for(int i=L.length ; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
        if(j == i-1)
            printf("%hd", aux->info);
        else
            aux = aux->next;
        }
        if (i > 1)
                printf(", ");

        else if (i == 0)
            printf("]");
      	aux = L.first;
    }
}

unsigned contaoc(TListSE *L, Tdata x)
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

void removex(TListSE *L, Tdata x)
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
		     aux2=aux->next->next;
			   free(aux->next);
				 aux->next=aux2;
		     L->length--;
     }
}

void RemoveX(short x, TListSE *L)
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
            L->length-=1;}
        else{
            aux = aux->next;
            i++;}
    }
}

void concaten(TListSE *L,TListSE *L2)
{
	 TNode *aux = L->last;
	 TNode *aux2 = L2->first;
	 aux->next = aux2;
}

int main()
{
  // Declaração de variáveis
  TListSE L1, L2;

  // Inicialização da lista
  printf("Inicializando a lista L1...\n");
  initList(&L1);
	initList(&L2);
  printf("Lista inicializada!\n");

  // Verificando lista vazia
  emptyList(L1)? printf("Lista vazia!\n"): printf("Lista não vazia!\n");

  // insere pela esquerda
  insertLeft(1, &L1);
  insertLeft(2, &L1);
  insertLeft(3, &L1);

	insertLeft(1, &L2);
  insertLeft(2, &L2);
  insertLeft(3, &L2);

  // insere pela direita
  insertRight(4, &L1);
  insertRight(5, &L1);
  insertRight(6, &L1);
  insertRight(6, &L1);

 // Imprimindo a lista
   printf("L1 = ");
   printList(&L1);
   printf("\n");


	 concaten(&L1, &L2);
	 printf("L1 = ");
   printList(&L1);
   printf("\n");
	 RemoveX(6, &L1);
	 printf("L1 = ");
   printList(&L1);
   printf("\n");
  // Deletando a lista
  printf("Deletando a lista L1...\n");
  deleteList(&L1);
  printf("Lista deletada!\n");

	return 0;
}
