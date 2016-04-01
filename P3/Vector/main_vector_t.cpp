//Compilar con: g++ -std=c++11 main_vector_t.cpp ../Entero/entero.cpp ../Complejo/complejo.cpp ../Racional/racional.cpp ../Real/real.cpp

#include "vector_t.hpp"

#include "../numero_t.hpp"
#include "../Racional/racional.hpp"
#include "../Complejo/complejo.hpp"
#include "../Entero/entero.hpp"
#include "../Real/real.hpp"

using namespace std;

int main(void)
{
	vector_t<complejo> A(10);
	vector_t<complejo> B(10);

	for(int i = 0; i < 5; i++)
	{
		A[i] = i;
		B[i] = i + 5;
	}

	cout << B[3] << endl;

	B[3] = 25;

	cout << B[0] << endl;
	cout << B[1] << endl;
	cout << B[2] << endl;
	cout << B[3] << endl;
	cout << B[4] << endl;

}