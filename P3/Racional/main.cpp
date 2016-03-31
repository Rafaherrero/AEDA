#include "racional.hpp"

using namespace std;

int main(void)
{
	racional A(32,10);
	cout << "Este es A: " << A << endl;
	racional B(34,12);
	cout << "Este es B: " << B << endl;
	cout << "Esta es la suma de A y B: " << A+B << endl;
	cout << "Esta es la multiplicacion de A y B: " << A*B << endl;
}