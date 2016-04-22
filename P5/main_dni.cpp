#include "dni.hpp"

using namespace std;

int main (void){
	cout << "Probando clase DNI" << endl;
	cout << "Introduzco el DNI 12345678" << endl;
	dni A(12345678);
	cout << "Compruebo si el DNI es correcto: " << A.get_dni() << endl;
}