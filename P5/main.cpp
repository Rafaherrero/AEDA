//Compilar usando g++ -std=c++11 main.cpp dni.cpp

#include "common.hpp"
#include "dni.hpp"
#include "Algoritmos/burbuja.hpp"
#include "Algoritmos/insercion.hpp"

using namespace std;

void error(void){
	cin.ignore();
	cout << endl << "La opcion introducida no es valida. Presione enter e introduzca otra.";
	cin.ignore();
	write(1,"\033[H\033[2J",7); //Esto sustituye al nada recomendable system("clear")
}

int main (void){

	unsigned opc = 2;
	unsigned ct_pruebas = 25;
	unsigned alg_ejecutar = 5;

	while (opc != 0 && opc != 1){
		cout << "================ " << "ORDENACION" << " =================" << endl;
		cout << "Seleccione el modo con el que desea trabajar: " << endl;
		cout << "0. Modo demostración" << endl;
		cout << "1. Modo estadisticas" << endl;
		cout << "Introduzca una opcion: ";
		cin >> opc;
		if (opc != 0 && opc != 1)
			error();
	}

	if (opc==0){
		while (!(alg_ejecutar>=0 && alg_ejecutar<=4)){ //alg_ejecutar != 0 && alg_ejecutar != 1 && alg_ejecutar != 2 && alg_ejecutar != 3 && alg_ejecutar != 4
			write(1,"\033[H\033[2J",7);
			cout << "============= " << "MODO DEMOSTRACIÓN" << " =============" << endl;
			cout << "Introduzca el numero de pruebas a realizar: ";
			cin >> ct_pruebas;
			cout << "Seleccione el algoritmo que quiere probar: " << endl;
			cout << "0. Algoritmo Burbuja" << endl;
			cout << "1. Algoritmo Insercion" << endl;
			cout << "2. Algoritmo MergeSort" << endl;
			cout << "3. Algoritmo QuickSort" << endl;
			cout << "4. Algoritmo ShellSort" << endl;
			cout << "Introduzca una opcion: ";
			cin >> alg_ejecutar;
			if (!(alg_ejecutar>=0 && alg_ejecutar<=4))
				error();
		}

		switch (alg_ejecutar){
			case 0:{
				write(1,"\033[H\033[2J",7);
				cout << "=========== " << "DEMOSTRACIÓN BURBUJA" << " ============" << endl;
				vector<dni> vector_dni(ct_pruebas);
				
				for (int i=0;i<vector_dni.size();i++)
					vector_dni[i].set_random();

				vector<dni> B(0);
				B = burbuja(vector_dni,0);
				
				break;
			}
			case 1:{
				write(1,"\033[H\033[2J",7);
				cout << "========== " << "DEMOSTRACIÓN INSERCION" << " ===========" << endl;
				vector<dni> vector_dni(ct_pruebas);
				for (int i=0;i<vector_dni.size();i++)
					vector_dni[i].set_random();

				vector<dni> I(0);
				I = insercion(vector_dni,0);
				
				break;
			}
		}
	}
}







/*
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
}*/