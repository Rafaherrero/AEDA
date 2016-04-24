#include "dni.hpp"

dni::dni(void):
	dni_(0)
{}

dni::dni(unsigned long int dni_entrada):
dni_(0)
{
	set_dni(dni_entrada);
}

dni::~dni(void){}

unsigned long int dni::get_dni(void){
	return dni_;
}

void dni::set_dni(unsigned long int dni_entrada){
	if (dni_entrada < 8000000 || dni_entrada > 99999999){
		cout << "El DNI introducido no es válido. Se insertará un DNI aleatorio" << endl;
		set_random();
	}
	else{
		dni_ = dni_entrada;
	}
}

void dni::set_random(void){
	random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator (http://www.cplusplus.com/reference/random/mersenne_twister_engine/)
    uniform_int_distribution<> distr(8000000, 99999999); // define the range
    dni_ = distr(eng);
}

bool dni::operator<(dni& dni_cp){
	return dni_ < dni_cp.get_dni();
}

bool dni::operator>(dni& dni_cp){
	return dni_ > dni_cp.get_dni();
}

bool dni::operator<=(dni& dni_cp){
	return dni_ <= dni_cp.get_dni();
}

bool dni::operator>=(dni& dni_cp){
	return dni_ >= dni_cp.get_dni();
}

ostream& operator<<(ostream& os, const dni& dni_salida)
{
    os << dni_salida.dni_;
    return os;
}
