#include "../numero_t.hpp"
#include "../Racional/racional.hpp"
#include "../Complejo/complejo.hpp"
#include "../Entero/entero.hpp"
#include "../Real/real.hpp"
#include "stack_t.hpp"

using namespace std;

int main(void)
{

	stack_t<racional> A(10);
	racional B(35,3);

	for (int i=0;i<A.size();i++){
		A.push(B);
	}

	cout << "Elemento primero de la pila A: " << A.top() << endl;
	cout << "Modificamos el primer elemento de la pila A poniendo un 150." << endl;
	cout << "Elementos de la pila A: " << A.size() << endl;
	
	A.top()=150;

	for (int i=0;i<A.size();i++){
		cout << A.top() << endl;
		A.pop();
	}

	cout << "Cambiamos el tamaño de la pila a 5 elementos." << endl;

	A.resize(5);

	cout << "Elementos de la pila A: " << A.size() << endl;

	for (int i=0;i<A.size();i++){
		A.push(B);
	}
}