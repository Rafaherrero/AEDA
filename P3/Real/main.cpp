#include "real.hpp"

using namespace std;

int main (void){
	real A(3);
	cout << "Numero A: " << A << endl;
	real B(-7.56678);
	cout << "Numero B: " << B << endl;
	cout << "Suma de A y B: " << A+B << endl;
	cout << "Multiplicacion de A y B: " << A*B << endl;
	real C(0.002);
	cout << "Numero C: " << C << endl;
	cout << "Division de A y C: " << A/C<< endl;
}