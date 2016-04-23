//Compilar usando 

#include "common.hpp"
#include "dni.hpp"
#include "Algoritmos/insercion.hpp"

using namespace std;

int main (void){

	vector<dni> vector_dni(3);

	for (int i=0;i<vector_dni.size();i++){
		vector_dni[i].set_random();
		cout << vector_dni[i].get_dni() << endl;
	}
	insercion(vector_dni);
}