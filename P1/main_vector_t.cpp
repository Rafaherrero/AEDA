#include "common.hpp"
#include "vector_t.hpp"

#include <iostream>

using namespace std;

int main(void)
{
	vector_t A(10);
	vector_t B;

	B.resize(5);
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

	const vector_t& C = A;
	A[2] = 6;
	C[2] = 3; 

	cout << A[2] << endl;
	cout << C[2] << endl;

	vector_t& D = A;
	D[2] = 3;

	cout << C[2] << endl;
}