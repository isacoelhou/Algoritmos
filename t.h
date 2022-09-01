//t.h
#define MAX 10

//tipo de dados
typedef struct
{
	int data[MAX];
	int size;
}IntVet;

typedef struct
{
	int *data;
	int size;
}intDinVet;
//prototipo das funções

// inicialização do vetor
void initIntVet(IntVet *V);

//função para ler o vetor
void scanIntVet(IntVet *V);

// função para imprimir um vetor
//void printVet(float *V, int n)
//parametros:
// V: vetor a ser lido
// n: n de elementos
void printVet(float *V, int size);

// soma os elementos do vetor
float sumVet(float *V, int size);

float media(float *V, int size);
