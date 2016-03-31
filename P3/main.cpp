#include "numero_t.hpp"
#include "Racional/racional.hpp"

using namespace std;

int main(void)
{
	numero_t* p1 = new racional(32/2);
	cout << "Mi racional es: " << *p1 << endl;
}