#include <stdio.h>

// a função a seguir calcula o fatorial de um número n escolhido pelo usuário
unsigned fatorial(int n)
{
  if (n == 0) //  se n = 0, seu fatorial é 1
  return 1;
  else if (n == 1) // quando chegamos em um, ou ele retorna seu próprio valor, ou ele retorna a soma das multiplicações anteriores
  return n;
  else
  return n *= fatorial(n-1); // definição de fatorial n * n-1
}

int main () {
  int n;

  while (scanf("%d",&n) && n)
    printf("%u", fatorial(n));
  return 0;
}
