#include "../common.hpp"
#include "dlinkedlist_t.hpp"

using namespace std;

int main(void)
{
	dlinkedlist_t A;
	dll_node_t nodo[10];

	for (int i=0; i<10; i++){
		nodo[i].set_dato(i+2*i);
		A.insert_end(&nodo[i]);
	}

	unsigned int tamano_lista = A.size();
	for (int i=0;i<tamano_lista;i++){
		dll_node_t* nodo=A.extract_end();
		cout << nodo->get_dato() << endl;
	}
}