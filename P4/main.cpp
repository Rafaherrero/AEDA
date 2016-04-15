//Compilar usando g++ -std=c++11 main.cpp tabla_hash.cpp clave.cpp

#include "tabla_hash.hpp"

using namespace std;

int main (void){
	tabla_hash<int> prueba(7,2,1);
	for (int i=0; i<100; i++){
		prueba.insertar(3);
	}
}