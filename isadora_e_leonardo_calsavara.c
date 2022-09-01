// isadora coelho araujo e leonardo calsavara

#include <stdio.h>
#include<string.h>

//questao 1
unsigned soma(unsigned a, unsigned b)
{
    if (b == 0)
        return a;
    else
    return a + soma(1, b-1);
}

//questao 2
unsigned mult(unsigned a, unsigned b)
{
    if (b == 0)
        return b;
    else
    return a + mult(a, b-1);
}

//questao 3
float f1(unsigned a)
{
    if(a==1){
        return (float)a;
    }else{
        return ((1/(float)a) + f1(a-1));
    }
}

//questao 4
float f2(unsigned a)
{
    if (a == 1)
    return (2/(float)4);
    else
    return (((a * a) + 1.0) / (a + 3.0)) + f2 (a - 1);
}

//questao 5
float f3(unsigned a)
{
    if(a<3)
        return a;
    else
        return ((float)2*f3(a-1)) + ((float)3*f3(a-2));
}

//questao 6
unsigned ack(unsigned m, unsigned n)
{
    if(m==0)
        return n+1;
    else if(m!=0 && n==0)
        return ack(m-1,1);
    else
        return ack(m-1, ack(m,n-1));
}

//questao 7
unsigned mdc( unsigned a, unsigned b)
{
    if(b==0)
        return a;
    else
        return mdc(b,a%b);
}


//questao 8
void scanV(float *v, int n)
{
    if(n>0)
    {
        v[n-1]=n;
        return scanV(v,n-1);
    }
}

float sumV(float *v, int n)
{
    float soma;
    if(n==0)
        soma+=0;
    else if(n==1)
    {
        soma+=v[n-1];
    }
    else if(n>1)
    {
        soma+=v[n-1];
        return soma + sumV(v,n-1);
    }}

//questão 9
char *invstr(char *inv, int a, int b)
{
    char c;
    if(a>=b)
    {
        return inv;
    }

    else if(inv[a]!=' ' && inv[b]!=' ')
    {
        c=inv[a];
        inv[a]=inv[b];
        inv[b]=c;
        return invstr(inv, a+1, b-1);
    }
}

//função a seguir fala se é ou não um palindrome
char palindrom(char *inv, int b)
{
    char c[50];
    unsigned x;
    strcpy(c,inv);
    invstr(c,0,b);
    x=strcmp(c,inv);
    if(x==0)
        return printf("A palavra/frase: %s eh um palindrome\n", c);
    else
        return printf("A palavra/frase: %s nao eh um palindrome\n", c);
}

//questao 10
unsigned f10(char y, char *x)
{
    unsigned laco = 0;
    if(x[0] == y)
        laco++;
    if(strlen(x)==1)
        return laco;
    sscanf(&x[1],"%[^\n]s", x);
        return laco + f10(y, x);
}

int main()
{
    unsigned x, y, a, l, c, d, e, f;
    int w;
    float *v;
    printf("A seguir estão a questão 1 e 2\n");
    printf("Digite dois números inteiros e maiores que 0, eles serão somados e multiplicados.\n");
    scanf("%u %u", &x, &y);
    printf("O resultado da sua soma é:\n");
    printf("%u\n", soma(x,y));
    printf("O resultado da sua multiplicacao é:\n");
    printf("%u\n", mult(x,y));
    printf("--------------------------------------------------------------------\n");
    printf("A seguir estão a questão 3 e 4\n");
    printf("Digite um número inteiro para uma soma enesima\n");
    scanf("%u", &a);
    printf("O resultado da sua soma de 1/n até um %u é:\n", a);
    printf("%.2f\n", f1(a));
    printf("O resultado da sua soma de (n^n + 1)(𝑛+3) até um %u é:\n", a);
    printf("%.2f\n", f2(a));
    printf("--------------------------------------------------------------------\n");
    printf("A seguir esta a questão 5\n");
    scanf("%u", &l);
    printf("%.2f\n", f3(l));
    printf("--------------------------------------------------------------------\n");
    printf("A seguir esta a questão 6\n");
    scanf("%u %u", &c, &d);
    printf("%u", ack(c,d));
    printf("--------------------------------------------------------------------\n");
    printf("A seguir esta a questão 7\n");
    scanf("%u %u", &e, &f);
    printf("%u\n", mdc(e,f));
    printf("--------------------------------------------------------------------\n");
    printf("A seguir esta a questão 8\n");
    scanf("%d", &w);
    scanV(v,w);
    printf("A soma do seu vetor é:\n");
    printf("%.2f\n", sumV(v,w));
    printf("--------------------------------------------------------------------\n");
    printf("A seguir esta a questão 9\n");
    char s[50];
    scanf("%[^\n]s", s);
    getchar();
    invstr(s,0,strlen(s)-1);
    palindrom(s,strlen(s)-1);
    printf("--------------------------------------------------------------------\n");
    printf("A seguir esta a questão 10\n");
    char p[100], q;
    printf("digite uma cadeia:\n");
    scanf("%[^\n]s", p);
    getchar();
    printf("agora um caractere:\n");
    scanf("%c", &q);
    getchar();
    printf("O seu caractere repete %d vezes na cadeia", f10(q,p));
    return 0;
}
