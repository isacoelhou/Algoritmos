//teste rapido
//implementar uma classe para numeros racionais
#include <iostream>
using namespace std;

//Declaracao de classe Racional

class Complexos
{
	private:
		float real; //numerador
		float imag; //numerador imag

	public:
		Complexos();//construtor default
		Complexos(float real, float imag);//contrutor parametrizado
		Complexos(const Complexos &B);
		~Complexos();	//destruidor
		void print();	//Imprime o objeto racional
		void scan(); //Leitura do objeto racional
		Complexos add(const Complexos &B);
		Complexos sub(const Complexos &B);
		Complexos mult(const Complexos &B);
		Complexos div(const Complexos &B);
};

//============================================
//Implementacao dos metodos de classe Racional
//============================================

Complexos::Complexos()
{
	cout << "construindo Complexo (Default)\n";
	this->real = 0;
	this->imag = 0;
}

Complexos::Complexos(float real, float imag)
{
	cout << "construindo Complexo (Parametrizado)\n";
	this->real = real;
	this->imag = imag;
}


Complexos::Complexos(const Complexos &B)
{
	cout << "construindo Racional (Cópia)\n";
	this->real = B.real;
	this->imag = B.imag;
}

Complexos::~Complexos()
{
	cout << "Destruindo Racional\n";
}


void Complexos::print()
{
	cout << "(" << this->real << "+" << this->imag << "i)";
	return;
}

void Complexos::scan()
{
	//cin.ignore();
	cin >> this->real;
	//cin.ignore();
	cin >> this->imag;
	//cin.ignore();
}

Complexos Complexos::add(const Complexos &B)
{
	Complexos S;
	S.real = this->real+B.real;
	S.imag = this->imag+B.imag;
	return S;
}

Complexos Complexos::sub(const Complexos &B)
{
	Complexos S;
	S.real = this->real-B.real;
	S.imag = this->imag-B.imag;
	return S;
}


Complexos Complexos::mult(const Complexos &B)
{
    Complexos S;
    S.real = this->real*B.real-this->imag*B.imag;
    S.imag = this->real*B.imag+B.real*this->imag;
    return S;
}

Complexos Complexos::div(const Complexos &B)
{
    Complexos S;
    S.real = (this->real*B.real+this->imag*B.imag)/(B.imag*B.imag+B.real*B.real);
    S.imag = (B.real*this->imag-this->real*B.imag)/(B.imag*B.imag+B.real*B.real);
    return S;
}
//================
//Funcao principal
//================
int main()
{
	system ("clear");
	cout << "<<< Classe Complexos >>>\n";
	cout << endl << endl;

	cout << "Declarando variaveis Complexas:\n";
	Complexos A, B(2,12), C(0,0);

	cout << endl;

	// Impressão dos valores iniciais
	cout << "Valores iniciais das variaveis:\n";
	cout << "A = ";
	A.print();
	cout << endl;

	cout << "B = ";
	B.print();
	cout << endl;

	//leitura de novos valores para os objetos
	cout << "Lendo os objetos\n";

	cout << "A = ";
	A.scan();

	cout << "B = ";
	B.scan();

	cout << endl << endl;

	//Novos valores
	cout << "Novos valores:\n";
	cout << "A = ";
	A.print();
	cout << endl;

	cout << "B = ";
	B.print();
	cout << endl;

	cout << "Operacao de soma: \n";
	C = A.div(B);

	cout << "C = ";
	C.print();
	cout << endl << endl;

	return 0;
}



