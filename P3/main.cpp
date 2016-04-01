//Compilar con g++ -std=c++11 main.cpp numero_t.cpp Racional/racional.cpp Complejo/complejo.cpp Entero/entero.cpp Real/real.cpp

#include "numero_t.hpp"
#include "Racional/racional.hpp"
#include "Complejo/complejo.hpp"
#include "Entero/entero.hpp"
#include "Real/real.hpp"
#include "excepciones.hpp"

using namespace std;

int main(void)
{
	numero_t* p1 = new racional(32,2);
	cout << "Mi racional es: " << *p1 << endl;
	numero_t* p2 = new complejo(12,5);
	cout << "Mi complejo es: " << *p2 << endl;
	numero_t* p3 = new entero(-58);
	cout << "Mi entero es: " << *p3 << endl;
	try{
	p1 = new racional(p2 -> toRacional());
	}catch(...){
		cerr << endl << "Error en la precision" << endl;
	}
	p1 = new racional(p2 -> toRacional());
	cout << "Ahora mi racional cambia de valor: " << *p1 << endl;
	numero_t* p4 = new racional();
	try{
	p4 = new racional(p2 -> toRacional());
	}catch(...){
	 	cerr << endl << "Error en la precision" << endl;
	}
	p4 = new racional(p2 -> toRacional());
	cout << "Ahora mi entero es un racional y vale: " << *p4 << endl;
}