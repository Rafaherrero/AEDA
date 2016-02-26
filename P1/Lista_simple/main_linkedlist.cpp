#include "../common.hpp"
#include "linkedlist_t.hpp"

using namespace std;

int main(void)
{
	linkedlist_t A;
	node_t nodo[10];

	for (int i=0; i<10; i++){
		nodo[i].set_dato(i+2*i);
		A.insertar_inicio(&nodo[i]);
	}

	for (int i=0;i<A.size();i++){
		node_t* nodo=A.extraer_inicio();
		cout << nodo->get_dato() << endl;
	}
}