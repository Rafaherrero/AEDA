#include "Racional/racional.hpp"
#include "Complejo/complejo.hpp"
#include "Pila/stack_t.hpp"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template<class TDATO> 
TDATO calculadora(istream& expresion){
	stack_t<TDATO> A(1);
	TDATO caracter;
	while (expresion.peek()!=-1){
		if (expresion.peek()>=48&&expresion.peek()<=57){
			expresion >> caracter;
			A.push(caracter);
		}
		else
			expresion.ignore();
	}
	cout << A.pop() << endl;
}

int main (void){
	char seleccion=0;
	stringstream expr;
	string expr_2;
	cout << endl << "==============================" << endl;
	cout << "Programa de calculadora en notación postfija" << endl;
	cout << "Seleccione una opción: " << endl;
	cout <<"[0] Calculadora de enteros." << endl;
	cout <<"[1] Calculadora de reales." << endl;
	cout <<"[2] Calculadora de racionales." << endl;
	cout <<"[3] Calculadora de complejos." << endl;
	cout << "Inserte su opción: ";
	cin >> seleccion;

	switch (seleccion){
		case '0':
			cout << endl << "Ha seleccionado la opción de enteros." << endl;
			cout << "Inserte su expresion: ";
			cin.ignore(); getline(cin, expr_2);
			expr << expr_2;
			calculadora<int> (expr);
			break;
		case '1':
		cout << endl << "Ha seleccionado la opción de reales." << endl;
			cout << "Inserte su expresion: ";
			cin.ignore(); getline(cin, expr_2);
			expr << expr_2;
			calculadora<float> (expr);
			break;
		case '2':
		cout << endl << "Ha seleccionado la opción de racionales." << endl;
			cout << "Inserte su expresion: ";
			cin.ignore(); getline(cin, expr_2);
			expr << expr_2;
			calculadora<racional> (expr);
			break;
		case '3':
		cout << endl << "Ha seleccionado la opción de complejos." << endl;
			cout << "Inserte su expresion: ";
			cin.ignore(); getline(cin, expr_2);
			expr << expr_2;
			calculadora<complejo> (expr);
			break;
		default:
			cout << endl << "Ha introducido una opción errónea" << endl;
			break;
		}
		
}

