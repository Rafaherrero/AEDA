//Compilar usando g++ -std=c++11 main.cpp dni.cpp

#include "common.hpp"
#include "dni.hpp"
#include "Algoritmos/burbuja.hpp"
#include "Algoritmos/insercion.hpp"
#include "Algoritmos/seleccion.hpp"
#include "Algoritmos/quicksort.hpp"

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
	unsigned tam_secuencia, num_rep;

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
			cout << "4. Algoritmo Seleccion" << endl;
			cout << "5. Algoritmo ShellSort" << endl;
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

				burbuja<dni>(vector_dni,0);
				break;
			}
			case 1:{
				write(1,"\033[H\033[2J",7);
				cout << "========== " << "DEMOSTRACIÓN INSERCION" << " ===========" << endl;
				vector<dni> vector_dni(ct_pruebas);
				for (int i=0;i<vector_dni.size();i++)
					vector_dni[i].set_random();

				insercion<dni>(vector_dni,0);				
				break;
			}
			case 3:{
				write(1,"\033[H\033[2J",7);
				cout << "========== " << "DEMOSTRACIÓN QUICKSORT" << " ===========" << endl;
				vector<dni> vector_dni(ct_pruebas);
				for (int i=0;i<vector_dni.size();i++)
					vector_dni[i].set_random();

				for (int i=0;i<vector_dni.size();i++)
					cout << vector_dni[i] << endl;
				cout << endl;
				quicksort<dni>(vector_dni,0);

				for (int i=0;i<vector_dni.size();i++)
					cout << vector_dni[i] << endl;

				break;
			}
			case 4:{
				write(1,"\033[H\033[2J",7);
				cout << "========== " << "DEMOSTRACIÓN SELECCION" << " ===========" << endl;
				vector<dni> vector_dni(ct_pruebas);
				for (int i=0;i<vector_dni.size();i++)
					vector_dni[i].set_random();

				seleccion<dni>(vector_dni,0);
				break;
			}

		}
	}
	else{
		vector<vector<unsigned long int>> resultados(6, vector<unsigned long int>(3));
		write(1,"\033[H\033[2J",7);
		cout << "============= " << "MODO ESTADÍSTICAS" << " =============" << endl;
		cout << "Introduzca el tamaño de la secuencia a analizar: ";
		cin >> tam_secuencia;
		cout << "Introduzca la cantidad de veces que quiera que se repitan las pruebas: ";
		cin >> num_rep;
		cout << endl << "                         NUMERO DE COMPARACIONES" << endl;
		cout << "                         Minimo - Promedio - Máximo" << endl;
		for (int i=0; i<6; i++){
			switch (i){
				case 0:{
					vector<unsigned long int> cp_burbuja(num_rep);
					vector<dni> vector_dni(tam_secuencia);
					unsigned long int suma = 0;
					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_dni.size();k++)
							vector_dni[k].set_random();
						cp_burbuja[j] = burbuja<dni>(vector_dni,1);
						suma += cp_burbuja[j];
					}
					burbuja<unsigned long int>(cp_burbuja,1);
					resultados[0][0] = cp_burbuja.front();
					resultados[0][1] = (suma/cp_burbuja.size());
					resultados[0][2] = cp_burbuja.back();

					cout << "Método de la burbuja: " << setw(9) << resultados[0][0] << setw(11) << resultados[0][1] << setw(9) << resultados[0][2] << endl;
					break;
				}
				case 1:{
					vector<unsigned long int> cp_insercion(num_rep);
					vector<dni> vector_dni(tam_secuencia);
					unsigned long int suma = 0;
					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_dni.size();k++)
							vector_dni[k].set_random();
						cp_insercion[j] = insercion<dni>(vector_dni,1);
						suma += cp_insercion[j];
					}
					insercion<unsigned long int>(cp_insercion,1);
					resultados[1][0] = cp_insercion.front();
					resultados[1][1] = (suma/cp_insercion.size());
					resultados[1][2] = cp_insercion.back();

					cout << "Método de inserción:  " << setw(9) << resultados[1][0] << setw(11) << resultados[1][1] << setw(9) << resultados[1][2] << endl;
					break;
				}

				case 3:{
					vector<unsigned long int> cp_quicksort(num_rep);
					vector<dni> vector_dni(tam_secuencia);
					unsigned long int suma = 0;
					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_dni.size();k++)
							vector_dni[k].set_random();
						cp_quicksort[j] = quicksort<dni>(vector_dni,1);
						suma += cp_quicksort[j];

					}
					
					insercion<unsigned long int>(cp_quicksort,1);
					resultados[3][0] = cp_quicksort.front();
					resultados[3][1] = (suma/cp_quicksort.size());
					resultados[3][2] = cp_quicksort.back();

					cout << "Método de quicksort:  " << setw(9) << resultados[3][0] << setw(11) << resultados[3][1] << setw(9) << resultados[3][2] << endl;
					break;
				}

				case 4:{
					vector<unsigned long int> cp_seleccion(num_rep);
					vector<dni> vector_dni(tam_secuencia);
					unsigned long int suma = 0;
					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_dni.size();k++)
							vector_dni[k].set_random();
						cp_seleccion[j] = seleccion<dni>(vector_dni,1);
						suma += cp_seleccion[j];
					}
					seleccion<unsigned long int>(cp_seleccion,1);
					resultados[4][0] = cp_seleccion.front();
					resultados[4][1] = (suma/cp_seleccion.size());
					resultados[4][2] = cp_seleccion.back();

					cout << "Método de seleccion:  " << setw(9) << resultados[4][0] << setw(11) << resultados[4][1] << setw(9) << resultados[4][2] << endl;
					break;
				}
			}
		}
	}
}