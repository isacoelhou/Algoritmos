// construção de uma classe de números complexos e implementação

#include <iostream>
#include <math.h>
using namespace std;

//===============================================
// Declaração da classe complexos
//===============================================

class complexos
{
    private:
        float real; //realerador
        float imag; //imaginário

    public:
        complexos(); //default
        complexos(float real, float den); //parametro
        complexos(const complexos &B); //construtor de cópia
        ~complexos();                  //destruidor
        void print();                 //imprime 
        void scan();                  //lê dados
        complexos add(const complexos &B); //soma 
        complexos sub(const complexos &B); //subtração
        complexos div(const complexos &B); //divisão
        complexos mult(const complexos &B); //multiplicação
};

//===============================================
// Implementação dos métodos da classe complexos
//===============================================

complexos::complexos()
{
    cout << "Contruindo complexos (Default)\n";
    this->real = 0;
    this->imag = 0;
}

complexos::complexos(float real, float imag)
{
    cout << "Contruindo complexos (Parametrizado)\n";
    this->real = real;
    this->imag = imag;
 }

complexos::complexos(const complexos &B)
{
    cout << "Contruindo complexos (Cópia)\n";
    this->real = B.real;
    this->imag = B.imag;
}

complexos::~complexos()
{
    cout << "Destruindo complexos \n";
}

void complexos::print()
{
    cout << "(" << this-> real;
    cout << "+";
    cout << this->imag <<"i" << ")";
}

void complexos::scan()
{
   cin >> this->real;
   cin >> this->imag;
}

complexos complexos::add(const complexos &B)
{
    complexos S;
    S.real = this->real + B.real;
    S.imag = this->imag + B.imag;
    return S;
}

complexos complexos::sub(const complexos &B)
{
    complexos S;
	S.real = this->real-B.real;
	S.imag = this->imag-B.imag;
     return S;
} 

complexos complexos::mult(const complexos &B)
{
    complexos S;
    S.real = this->real*B.real-this->imag*B.imag;
    S.imag = this->real*B.imag+B.real*this->imag;
    return S;
} 



//===============================================
// Função principal
//===============================================

int main()
{
    system("clear");
    cout << "<<<< Classe dos complexos >>>> \n";
    cout << endl << endl;

    cout << "Declarando variáveis complexas: \n\n";
    complexos A, B, C;
    cout << endl;
    
    // Impressão dos valores inciados
    cout << "Valores iniciais das variáveis: \n";
    cout << endl;
    cout << "A = ";
    A.print();
    cout << endl;
    cout << "B = ";
    B.print();
    cout << endl;
    cout << endl;
    cout << endl;

    //leitura
    cout << "Insira novos valores para os objetos A e B: \n\n";
    cout << "B = ";
    B.scan();
    cin.ignore();

    // Impressão dos valores inciados
    A.scan();
    cout << "Novos valores das variáveis: \n";
    cout << endl;
    cout << "A = ";
    A.print();
    cout << endl;
    cout << "B = ";
    B.print();
    cout << endl;
    cout << endl;
    cout << endl;
    
    C = A.add(B);
    C.print();

    C = A.sub(B);
    C.print();

    C = A.mult(B);
    C.print();


    return 0;
}

