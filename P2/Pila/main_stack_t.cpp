#include "stack_t.hpp"
#include "../Racional/racional.hpp"

using namespace std;

int main(void)
{

	stack_t<racional> A(10);
	racional B(34,2);

	for (int i=0;i<A.size();i++){
		A.push(B);
	}

	cout << "Elemento primero de la pila A: " << A.top() << endl;
	cout << "Modificamos el primer elemento de la pila A poniendo un 150." << endl;
	cout << "Elementos de la pila A: " << A.size() << endl;
	
	A.top()=150;

	for (int i=0;i<A.size();i++){
		cout << A.pop() << endl;
	}

	cout << "Cambiamos el tamaño de la pila a 5 elementos." << endl;

	A.resize(5);

	cout << "Elementos de la pila A: " << A.size() << endl;

	for (int i=0;i<A.size();i++){
		A.push(B);
	}
}