//Leonardo Calsavara e Isadora Coelho
// construção de uma classe de números mistos e implementação

#include <iostream>
#include <math.h>
using namespace std;

//===============================================
// Declaração da classe mistos
//===============================================

class mistos
{
    private:
        int real; //realerador
        int num; 
        int den; 
    public:
        mistos(); //default
        mistos(int real, int num, int den); //parametro
        mistos(const mistos &B); //construtor de cópia
        ~mistos();                  //destruidor
        void print();               //imprime
        void scan();                //le
        int MDC(int n, int d);      //mdc
        void simplifica();          //simplificação
        mistos soma(const mistos &B); //soma
        mistos sub(const mistos &B); //subtração
        mistos mult(const mistos &B); //multiplicação
        mistos div(const mistos &B); //divisão
};

//===============================================
// Implementação dos métodos da classe mistos
//===============================================

mistos::mistos()
{
    cout << "Contruindo mistos (Default)\n";
    this->real = 0;
    this->num = 0;
    this->den = 0;
}

mistos::mistos(int real, int num, int den)
{
    cout << "Contruindo mistos (Parametrizado)\n";
    this->real = real;
    this->num = num;
    this->den = den;
 }

mistos::mistos(const mistos &B)
{
    cout << "Contruindo mistos (Cópia)\n";
    this->real = B.real;
    this->num = B.num;
    this->den = B.den;
}

mistos::~mistos()
{
    cout << "\n";
}

void mistos::print()
{
    if(!this->real)
    {
    cout << this->num << "/" << this->den;
    cout << endl;
    }
    else if(!this->num)
       cout << this-> real; 
    else{
    cout << this-> real << " ";
    cout << this->num << "/" << this->den;
    }
}

void mistos::scan()
{
    cin >> this->real;
    cin.ignore();
    cin >> this->num;
    cin.ignore();
    cin >> this->den;
}

int mistos::MDC(int n, int d)
{
    int r;
    while (d)
    {
        r = n%d;
        n = d;
        d = r;
    }

    return n;
}

void mistos::simplifica()
{
    int mdc = MDC(this->num, this->den);
    if( this->num / this->den != 0)
    this->real = this->num / this->den;
    this->num = this->num%this->den;
    this->num /= mdc;
    this->den /= mdc;
}

mistos mistos::soma(const mistos &B)
{
    mistos S;
    S.real = this->real + B.real;
    S.den = this->den * B.den;
    S.num = this->num * B.den + B.num * this->den;
    S.simplifica();
    return S;
}

mistos mistos::sub(const mistos &B)
{
    mistos S, Q, R;
    S.num = (this->den*this->real)+this->num;
    Q.num = (B.den*B.real)+B.num;
    S.den = this->den;
    Q.den = B.den;

    R.num = (S.num*Q.den) - (S.den*Q.num);
    R.den = S.den*Q.den;

    return R;
}

mistos mistos::mult(const mistos &B)
{
    mistos S;
    S.real = 0;
    S.num = ((this->den*this->real)+this->num) * ((B.den*B.real)+B.num);
    S.den = this->den * B.den;
    S.simplifica();
    return S;
}

mistos mistos::div(const mistos &B)
{
    mistos S;
    S.real = 0;
    S.num = ((this->den*this->real)+this->num) * B.den;
    S.den = this->den * ((B.den*B.real)+B.num);
    S.simplifica();
    return S;
}


//===============================================
// Função principal
//===============================================

int main()
{
    system("clear");
    cout << "<<<< Classe dos números mistos >>>> \n";
    cout << endl << endl;

    cout << "Declarando variáveis mistas: \n\n";
    mistos A(2,1,3), B(A), C(1,2,3), D(A);
    mistos F;
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
    cout << "C = ";
    C.print();
    cout << endl;

    cout << "Digite um novo valor para B\n" << endl;
    cout << "B = ";
    B.scan();
    cout << endl;

    cout << "Resultado da soma de B e A" << endl;
    F = B.soma(A);
    cout << "A+B = ";
    F.print();
    cout << endl;
    cout << "Obs: O resultado já está simplificado\n" << endl;

    cout << "Resultado da subtração de C em A (A-C)\n";
    F = A.sub(C);
    cout << "A-C = ";
    F.print();
    cout << endl;

    cout << "Multiplicação de A por D\n";
    F = A.mult(D);
    cout << "A * D = ";
    F.print();
    cout << endl;

    cout << "Por fim, divisão de C por A\n";
    F = C.div(A);
    cout << "C / A = ";
    F.print();

    return 0;
}

