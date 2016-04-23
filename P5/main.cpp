//Compilar usando 

#include "common.hpp"
#include "dni.hpp"
#include "Algoritmos/burbuja.hpp"
#include "Algoritmos/insercion.hpp"

using namespace std;

int main (void){

	vector<dni> vector_dni_1(5);
	cout << "Vector antes de ordenar por insercion: " << endl;
	for (int i=0;i<vector_dni_1.size();i++){
		vector_dni_1[i].set_random();
		cout << vector_dni_1[i].get_dni() << endl;
	}
	vector<dni> A(0);
	A = insercion(vector_dni_1);
	cout << endl << "Vector después de ordenar por insercion: " << endl;
	for (int i=0;i<A.size();i++){
		cout << A[i].get_dni() << endl;
	}

	vector<dni> vector_dni_2(5);
	cout << "Vector antes de ordenar por burbuja: " << endl;
	for (int i=0;i<vector_dni_2.size();i++){
		vector_dni_2[i].set_random();
		cout << vector_dni_2[i].get_dni() << endl;
	}
	vector<dni> B(0);
	B = burbuja(vector_dni_2);
	cout << endl << "Vector después de ordenar por burbuja: " << endl;
	for (int i=0;i<B.size();i++){
		cout << B[i].get_dni() << endl;
	}
}