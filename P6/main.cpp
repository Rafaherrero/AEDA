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
	return 0;
}