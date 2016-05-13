//Compilar usando g++ -std=c++11 main.cpp dni.cpp

#include "common.hpp"
#include "dni.hpp"
#include "nodo.hpp"
#include "insercion.hpp"
#include "arbol.hpp"

using namespace std;

unsigned opc_demo=4;

void borrar_pantalla (void){
	write(1,"\033[H\033[2J",7); //Esto sustituye al nada recomendable system("clear")
}

void error(void){
	cin.ignore();
	cout << endl << "La opcion introducida no es valida. Presione enter e introduzca otra.";
	cin.ignore();
	borrar_pantalla();
}

void calcular_cp(vector<float> &com, vector<vector<float>> &v, float sm, unsigned int modo_){
	
	insercion<float>(com,1);

	v[modo_][0] = com.front();
	v[modo_][1] = ((com.front()+com.back())/2);
	v[modo_][2] = com.back();
}

void randomizar(vector<dni> &v){
	for (int i=0;i<v.size();i++)
		v[i].set_random();
}



int main(void){
	unsigned opc=3, tam_arbol, num_rep;

	while (opc != 0 && opc != 1 && opc != 2){
		cout << "================ " << "ARBOL BINARIO DE BUSQUEDA" << " =================" << endl;
		cout << "Seleccione el modo con el que desea trabajar: " << endl;
		cout << "0. Modo demostración" << endl;
		cout << "1. Modo estadisticas" << endl;
		cout << "2. Salir" << endl;
		cout << "Introduzca una opcion: ";
		cin >> opc;
		if (opc != 0 && opc != 1 && opc != 2)
			error();
	}

	if (opc==0){
		arbol<int> arbol_demo;
		do{
		while (opc_demo != 0 && opc_demo != 1 && opc_demo != 2 && opc_demo !=3){
			borrar_pantalla();
			cout << "============= " << "MODO DEMOSTRACIÓN CON INT" << " =============" << endl;
			cout << "0. Insertar clave" << endl;
			cout << "1. Eliminar clave" << endl;
			cout << "2. Mostrar arbol" << endl;
			cout << "3. Salir" << endl;
			cout << "Introduzca una opcion: ";
			cin >> opc_demo;
			if (opc_demo != 0 && opc_demo != 1 && opc_demo != 2 && opc_demo !=3)
				error();
		}

	switch (opc_demo){
		case 0:{
			int num=0;
			borrar_pantalla();
			cout << "============= " << "MODO DEMOSTRACIÓN CON INT" << " =============" << endl;
			cout << "Introduzca el número a insertar en el árbol: ";
			cin >> num;
			arbol_demo.insertar(num);
			cout << "El numero insertado es " << num << endl;
			cin.ignore(); cin.ignore();
			opc_demo = 4;
			break;
		}
		case 1:{
			int num=0;
			borrar_pantalla();
			cout << "============= " << "MODO DEMOSTRACIÓN CON INT" << " =============" << endl;
			cout << "Introduzca el número a eliminar en el árbol: ";
			cin >> num;
			arbol_demo.eliminar(num);
			cout << "El numero eliminado es " << num << endl;
			cin.ignore(); cin.ignore();
			opc_demo = 4;
			break;
		}
		case 2:{
			borrar_pantalla();
			cout << "============= " << "MODO DEMOSTRACIÓN CON INT" << " =============" << endl;
			arbol_demo.nivel_orden();
			cin.ignore(); cin.ignore();
			opc_demo = 4;
			break;
		}
		case 3:{
			cout << endl << "Gracias por utilizar el programa" << endl;
			return 0;
			break;
		}
	}
	}while(opc_demo != 3);
}
else if (opc==1){
		
		write(1,"\033[H\033[2J",7);
		cout << "============= " << "MODO ESTADÍSTICAS" << " =============" << endl;
		cout << "Introduzca el tamaño del arbol a analizar: ";
		cin >> tam_arbol;
		cout << "Introduzca la cantidad de veces que quiera que se repitan las pruebas: ";
		cin >> num_rep;
		cout << endl << "                               NUMERO DE COMPARACIONES" << endl;
		cout << "                            Minimo -  Promedio  -   Maximo" << endl;

		vector<dni> vector_dni(tam_arbol);
		vector<vector<float>> resultados(2, vector<float>(3));
		vector<float> comp(vector_dni.size());
		float suma = 0, suma_intermedio =0;

		for (int j=0; j<num_rep; j++){
			arbol<dni> arbol_esta;
			for (int k=0;k<vector_dni.size();k++)
				vector_dni[k].set_random();
			for (int k=0;k<vector_dni.size();k++){
				comp[k] = arbol_esta.insertar(vector_dni[k]);
			}
		}
	
		calcular_cp(comp, resultados, suma, 0);

		cout << "Comparaciones insercion: " << setw(12) << resultados[0][0] << setw(12) << resultados[0][1] << setw(12) << resultados[0][2] << endl;
		suma=0;

		vector<dni> vector_dni_2(tam_arbol*2);
		vector<float> comp_2(vector_dni_2.size());

		for (int j=0; j<num_rep; j++){
			for (int k=0;k<vector_dni_2.size();k++)
				vector_dni_2[k].set_random();
			arbol<dni> arbol_esta;
			for (int k=0;k<vector_dni_2.size()/2;k++){
				arbol_esta.insertar(vector_dni_2[k]);
			}
			for (int k=0;k<vector_dni_2.size()/2;k++){
				arbol_esta.buscar(vector_dni_2[k]);
				 comp_2[k] = arbol_esta.get_esta();
			}
			for (int k=vector_dni_2.size()/2; k<vector_dni_2.size(); k++){
				arbol_esta.buscar(vector_dni_2[k]);
				comp_2[k] += arbol_esta.get_esta();
			}
		}

		calcular_cp(comp_2, resultados, suma, 0);

		cout << "Comparaciones búsqueda:  " << setw(12) << resultados[0][0] << setw(12) << resultados[0][1] << setw(12) << resultados[0][2] << endl;
		suma=0;

	}
else{
	cout << endl << "Gracias por utilizar el programa" << endl;
	return 0;
}

return 0;
}