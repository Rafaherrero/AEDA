#include "Racional/racional.hpp"
#include "Complejo/complejo.hpp"
#include "Pila/stack_t.hpp"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template<class TDATO> 
TDATO calculadora(istream& expresion){
	stack_t<TDATO> pila(1);
	TDATO caracter;
	TDATO caracter_2;
	while (expresion.peek()!=-1){
		if (expresion.peek()>=48&&expresion.peek()<=57){
			expresion >> caracter;
			pila.push(caracter);
		}
		else{
			if (expresion.peek()==32||(expresion.peek()!=42&&expresion.peek()!=43&&expresion.peek()!=45&&expresion.peek()!=47)){
				expresion.ignore();
			}
			else{
				if (expresion.peek()==42){
					caracter_2 = pila.pop();
					caracter = caracter_2+pila.pop();
					pila.push(caracter);
				}
			}
		}
	}
	return pila.pop();
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
		cout << "La solucion a su expresion es: " << calculadora<int>(expr) << endl;
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

