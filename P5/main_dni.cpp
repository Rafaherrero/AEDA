#include "dni.hpp"

using namespace std;

int main (void){
	cout << "Probando clase DNI" << endl;
	cout << "Introduzco el DNI 12345678" << endl;
	dni A(1234567844);
	cout << "Compruebo si el DNI es correcto: " << A.get_dni() << endl;
	cout << "Creamos otro DNI 23456789" << endl;
	dni B(23456789);
	cout << "Comprobamos los operadores de comparación sobrecargados" << endl;
	if (A<B)
		cout << "El operador < funciona" << endl;
	else
		cout << "El operador < no funciona" << endl;
	if (A>B)
		cout << "El operador > no funciona" << endl;
	else
		cout << "El operador > funciona" << endl;

	cout << "Creamos otro DNI igual que el 2 para probar <= y >=" << endl;
	dni C(23456789);

	if (B<=C)
		cout << "El operador <= funciona" << endl;
	else
		cout << "El operador <= no funciona" << endl;
	if (C>=B)
		cout << "El operador >= funciona" << endl;
	else
		cout << "El operador >= no funciona" << endl;

}