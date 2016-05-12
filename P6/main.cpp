//Compilar usando g++ -std=c++11 main.cpp dni.cpp

#include "common.hpp"
#include "dni.hpp"
#include "nodo.hpp"
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



int main(void){
	unsigned opc=3;

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

}
else{
	cout << endl << "Gracias por utilizar el programa" << endl;
	return 0;
}

return 0;
}