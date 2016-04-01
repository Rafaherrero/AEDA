//Compilar con

#include "list_t.hpp"
#include "../numero_t.hpp"
#include "../Racional/racional.hpp"
#include "../Complejo/complejo.hpp"
#include "../Entero/entero.hpp"
#include "../Real/real.hpp"
#include "list_t.hpp"

using namespace std;

int main(void)
{
	list_t<entero> A;
	node_t<entero> nodo[10];
	entero num(0);

	for (int i=0; i<10; i++){
		num = entero(i+2*i);
		nodo[i] = node_t<entero>(num);
		A.push_front(&nodo[i]);
	}

	while(!A.empty()){
		node_t<entero>* nodo=A.extract_front();
		cout << nodo->data() << endl;
	}
}