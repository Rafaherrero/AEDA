#include "../common.hpp"
#include "queue_t.hpp"
#include <typeinfo>

using namespace std;

int main(void)
{
	queue_t A(10);

	for (int i=0; i < A.size(); i++){
		A.push(i+2*i);
	}

	cout << "Elemento primero de la cola A: " << A.front() << endl;
	cout << "Elemento ultimo de la cola A: " << A.back() << endl;
	cout << "Elementos de la cola A: " << A.size() << endl;

	for (int i=0; i < A.size(); i++){
		cout << i+1 << ".- " << A.pop() << endl;
	}

	if (A.empty())
		cout << "La cola A esta vacia y deberia estar vacia" << endl;

	cout << "=============================================" << endl;

	queue_t B(5);

	for (int i=0; i < B.size(); i++){
		B.push(i+2*i);
	}

	cout << "Tamano de la cola B antes de cambiar tamano: " << B.size() << endl;

	B.resize(15);

	cout << "Tamano de la cola B despues de cambiar tamano: " << B.size() << endl;
	cout << "=============================================" << endl;

	queue_t C(10);

	for (int i=0; i < C.size(); i++){
		C.push(i+3*i);
	}

	 cout << "Elementos de la cola C antes de cambiar tamano: " << C.size() << endl;

	for (int i=0; i < C.size(); i++){
		cout << i+1 << ".- " << C.pop() << endl;
	}

	C.resize(10);

	for (int i=0; i < C.size(); i++){
		C.push(i+3*i);
	}

	C.resize_copia(5);

	cout << "Elementos de la cola C tras reducir en 5 su tamano: " << C.size() << endl;

	for (int i=0; i < C.size(); i++){
		cout << i+1 << ".- " << C.pop() << endl;
	}

	for (int i=0; i < C.size(); i++){
		C.push(i+3*i);
	}

	C.resize_copia(10);

	cout << "Elementos de la cola C tras aumentar en 5 su tamano: " << C.size() << endl;

	for (int i=0; i < C.size(); i++){
		cout << i+1 << ".- " << C.pop() << endl;
	}

	cout << "Cola C tras introducir los 10 elementos de su tamano: " << C.size() << endl;

	for (int i=0; i < C.size(); i++){
		C.push(i+3*i);
	}
	
	for (int i=0; i < C.size(); i++){
		cout << i+1 << ".- " << C.pop() << endl;
	}
}