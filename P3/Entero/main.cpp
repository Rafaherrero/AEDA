#include "entero.hpp"

using namespace std;

int main (void){
	entero A(3);
	cout << "Numero A: " << A << endl;
	entero B(-7);
	cout << "Numero B: " << B << endl;
	cout << "Suma de A y B: " << A+B << endl;
	cout << "Multiplicacion de A y B: " << A*B << endl;
	entero C(0);
	cout << "Numero C: " << C << endl;
	cout << "Division de A y C: " << A/C<< endl;
}