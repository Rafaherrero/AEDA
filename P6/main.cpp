//Compilar usando g++ -std=c++11 main.cpp

#include "common.hpp"
#include "dni.hpp"
#include "nodo.hpp"
#include "arbol.hpp"

using namespace std;

int main(void){
	dni B(23568941);
	nodo<dni> A(B);
	arbol<dni> C(&A);
	nodo<dni> *D = C.get_raiz();
	cout << B << endl;
	cout << D -> dato() << endl;
	arbol<dni> E;
	if (C.empty())
		cout << "El arbol esta vacio" << endl;
	else
		cout << "El metodo si funciona" << endl;

	cout << C.size() << endl;
	
	dni H(13568941);
	C.insertar(H);
	dni G(13568940);

	nodo<dni> *F = C.get_raiz();

	//cout << F -> dato()<< endl;
	//cout << F -> izquierda() -> dato() << endl;
	//cout << F -> derecha() -> dato() << endl;

	C.pre_orden();
	cout << endl;
	C.in_orden();
	cout << endl;
	C.post_orden();
	cout << endl;

	C.nivel_orden();
	cout << endl;

	return 0;
}