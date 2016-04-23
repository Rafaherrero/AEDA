//Compilar usando 

#include "common.hpp"
#include "dni.hpp"
#include "Algoritmos/insercion.hpp"

using namespace std;

int main (void){

	vector<dni> vector_dni(5);
	cout << "Vector antes de ordenar por insercion: " << endl;
	for (int i=0;i<vector_dni.size();i++){
		vector_dni[i].set_random();
		cout << vector_dni[i].get_dni() << endl;
	}
	vector<dni> C(0);
	C = insercion(vector_dni);
	cout << endl << "Vector después de ordenar por insercion: " << endl;
	for (int i=0;i<C.size();i++){
		cout << C[i].get_dni() << endl;
	}
}