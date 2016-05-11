//Compilar usando g++ -std=c++11 main.cpp

#include "common.hpp"
#include "dni.hpp"
#include "nodo.hpp"
#include "arbol.hpp"

using namespace std;

int main(void){
	dni B=34567821;
	nodo<dni> A(B);
	arbol<dni> C(A);
	cout << A.dato() << endl;
	return 0;
}