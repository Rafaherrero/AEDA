#include "numero_t.hpp"
#include "Racional/racional.hpp"
#include "Complejo/complejo.hpp"
#include "Entero/entero.hpp"

using namespace std;

int main(void)
{
	numero_t* p1 = new racional(32/2);
	cout << "Mi racional es: " << *p1 << endl;
	numero_t* p2 = new complejo(12,5);
	cout << "Mi complejo es: " << *p2 << endl;
	numero_t* p3 = new entero(-58);
	cout << "Mi entero es: " << *p3 << endl;
}