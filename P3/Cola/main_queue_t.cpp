//Compilar con g++ -std=c++11 main_queue_t.cpp ../Entero/entero.cpp ../Complejo/complejo.cpp ../Racional/racional.cpp ../Real/real.cpp

#include "queue_t.hpp"
#include "../numero_t.hpp"
#include "../Racional/racional.hpp"
#include "../Complejo/complejo.hpp"
#include "../Entero/entero.hpp"
#include "../Real/real.hpp"
#include <typeinfo>

using namespace std;

int main(void)
{
	queue_t<entero> A(10);

	for (int i=0; i < A.size(); i++){
		A.push(i+2*i);
	}

	cout << "Elemento primero de la cola A: " << A.front() << endl;
	cout << "Elemento ultimo de la cola A: " << A.rear() << endl;
	cout << "Elementos de la cola A: " << A.size() << endl;

	for (int i=0; i < A.size(); i++){
		cout << i+1 << ".- " << A.rear() << endl;
		A.pop();
	}

	if (A.empty())
		cout << "La cola A esta vacia y deberia estar vacia" << endl;

	cout << "=============================================" << endl;

	queue_t<entero> B(5);

	for (int i=0; i < B.size(); i++){
		B.push(i+2*i);
	}

	cout << "Tamano de la cola B antes de cambiar tamano: " << B.size() << endl;

	B.resize(25);

	cout << "Tamano de la cola B despues de cambiar tamano: " << B.size() << endl;
	cout << "=============================================" << endl;

	queue_t<entero> C(5);

	for (int i=0; i < C.size(); i++){
		C.push(i+3*i);
	}

	 cout << "Elementos de la cola C antes de cambiar tamano: " << C.size() << endl;

	for (int i=0; i < C.size(); i++){
		cout << i+1 << ".- " << C.rear() << endl;
		C.pop();
	}
}