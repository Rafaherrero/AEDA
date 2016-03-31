#include "complejo.hpp"

using namespace std;

int main (void){
	complejo A(2,3);
	cout << "Numero A: " << A << endl;
	complejo B(2,-3);
	cout << "Numero B: " << B << endl;
	cout << "Suma de A y B: " << A+B << endl;
	cout << "Multiplicacion de A y B: " << A*B << endl;

}