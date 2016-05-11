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
	return 0;
}