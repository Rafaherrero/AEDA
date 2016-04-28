//Compilar usando g++ -std=c++11 main.cpp dni.cpp

#include "common.hpp"
#include "dni.hpp"
#include "Algoritmos/burbuja.hpp"
#include "Algoritmos/insercion.hpp"
#include "Algoritmos/seleccion.hpp"
#include "Algoritmos/quicksort.hpp"
#include "Algoritmos/mergesort.hpp"
#include "Algoritmos/shellsort.hpp"

#define cantidad_algoritmos 6

using namespace std;

void error(void){
	cin.ignore();
	cout << endl << "La opcion introducida no es valida. Presione enter e introduzca otra.";
	cin.ignore();
	write(1,"\033[H\033[2J",7); //Esto sustituye al nada recomendable system("clear")
}

void calcular_cp(vector<float> &com, vector<vector<float>> &v, float sm, unsigned int num_alg){
	
	insercion<float>(com,1);

	v[num_alg][0] = com.front();
	v[num_alg][1] = (sm/com.size());
	v[num_alg][2] = com.back();
}

void randomizar(vector<dni> &v){
	for (int i=0;i<v.size();i++)
		v[i].set_random();
}

int main (void){

	unsigned opc = 2;
	unsigned ct_pruebas = 25;
	unsigned alg_ejecutar = 100;
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
		while (!(alg_ejecutar>=0 && alg_ejecutar<=(cantidad_algoritmos-1))){ //alg_ejecutar != 0 && alg_ejecutar != 1 && alg_ejecutar != 2 && alg_ejecutar != 3 && alg_ejecutar != 4
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
			if (!(alg_ejecutar>=0 && alg_ejecutar<=(cantidad_algoritmos-1)))
				error();
		}
		vector<dni> vector_dni(ct_pruebas);
		switch (alg_ejecutar){
			case 0:{
				write(1,"\033[H\033[2J",7);
				cout << "=========== " << "DEMOSTRACIÓN BURBUJA" << " ============" << endl;
				randomizar(vector_dni);

				burbuja<dni>(vector_dni,0);
				break;
			}
			case 1:{
				write(1,"\033[H\033[2J",7);
				cout << "========== " << "DEMOSTRACIÓN INSERCION" << " ===========" << endl;
				randomizar(vector_dni);

				insercion<dni>(vector_dni,0);		
				break;
			}
			case 2:{
				write(1,"\033[H\033[2J",7);
				cout << "========== " << "DEMOSTRACIÓN MERGESORT" << " ===========" << endl;
				randomizar(vector_dni);

				mergesort<dni>(vector_dni,0);

				break;
			}
			case 3:{
				write(1,"\033[H\033[2J",7);
				cout << "========== " << "DEMOSTRACIÓN QUICKSORT" << " ===========" << endl;
				randomizar(vector_dni);

				quicksort<dni>(vector_dni,0);
				break;
			}
			case 4:{
				write(1,"\033[H\033[2J",7);
				cout << "========== " << "DEMOSTRACIÓN SELECCION" << " ===========" << endl;
				randomizar(vector_dni);

				seleccion<dni>(vector_dni,0);
				break;
			}
			case 5:{
				write(1,"\033[H\033[2J",7);
				cout << "========== " << "DEMOSTRACIÓN SHELLSORT" << " ===========" << endl;
				randomizar(vector_dni);

				shellsort<dni>(vector_dni,0);
				break;
			}

		}
	}
	else{
		
		write(1,"\033[H\033[2J",7);
		cout << "============= " << "MODO ESTADÍSTICAS" << " =============" << endl;
		cout << "Introduzca el tamaño de la secuencia a analizar: ";
		cin >> tam_secuencia;
		cout << "Introduzca la cantidad de veces que quiera que se repitan las pruebas: ";
		cin >> num_rep;
		cout << endl << "                               NUMERO DE COMPARACIONES" << endl;
		cout << "                            Minimo -  Promedio  -   Maximo" << endl;

		vector<dni> vector_dni(tam_secuencia);
		vector<vector<float>> resultados(cantidad_algoritmos, vector<float>(3));
		vector<float> comp(num_rep);
		float suma = 0;

		for (int i=0; i<6; i++){
			switch (i){
				case 0:{
					
					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_dni.size();k++)
							vector_dni[k].set_random();
						comp[j] = burbuja<dni>(vector_dni,1);
						suma += comp[j];
					}

					calcular_cp(comp, resultados, suma, 0);

					cout << "Método de la burbuja: " << setw(12) << resultados[0][0] << setw(12) << resultados[0][1] << setw(12) << resultados[0][2] << endl;
					suma=0;
					break;
				}

				case 1:{
					
					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_dni.size();k++)
							vector_dni[k].set_random();
						comp[j] = insercion<dni>(vector_dni,1);
						suma += comp[j];
					}

					calcular_cp(comp, resultados, suma, 1);

					cout << "Método de inserción:  " << setw(12) << resultados[1][0] << setw(12) << resultados[1][1] << setw(12) << resultados[1][2] << endl;
					suma=0;
					break;
				}

				case 2:{

					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_dni.size();k++)
							vector_dni[k].set_random();
						comp[j] = mergesort<dni>(vector_dni,1);
						suma += comp[j];
					}
					
					calcular_cp(comp, resultados, suma, 2);

					cout << "Método de mergesort:  " << setw(12) << resultados[2][0] << setw(12) << resultados[2][1] << setw(12) << resultados[2][2] << endl;
					suma=0;
					break;
				}

				case 3:{

					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_dni.size();k++)
							vector_dni[k].set_random();
						comp[j] = quicksort<dni>(vector_dni,1);
						suma += comp[j];

					}
					
					calcular_cp(comp, resultados, suma, 3);

					cout << "Método de quicksort:  " << setw(12) << resultados[3][0] << setw(12) << resultados[3][1] << setw(12) << resultados[3][2] << endl;
					suma=0;
					break;
				}

				case 4:{

					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_dni.size();k++)
							vector_dni[k].set_random();
						comp[j] = seleccion<dni>(vector_dni,1);
						suma += comp[j];
					}
					
					calcular_cp(comp, resultados, suma, 4);

					cout << "Método de seleccion:  " << setw(12) << resultados[4][0] << setw(12) << resultados[4][1] << setw(12) << resultados[4][2] << endl;
					suma=0;
					break;
				}

				case 5:{

					for (int j=0; j<num_rep; j++){
						for (int k=0;k<vector_dni.size();k++)
							vector_dni[k].set_random();
						comp[j] = shellsort<dni>(vector_dni,1);
						suma += comp[j];
					}
					
					calcular_cp(comp, resultados, suma, 4);

					cout << "Método de shellsort:  " << setw(12) << resultados[4][0] << setw(12) << resultados[4][1] << setw(12) << resultados[4][2] << endl;
					suma=0;
					break;
				}
			}
		}
	}
}