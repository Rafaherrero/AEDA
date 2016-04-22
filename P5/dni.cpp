#include "dni.hpp"

dni::dni(void):
	dni_(0)
{}

dni::dni(unsigned long int dni_entrada):
dni_(0)
{
	if (dni_entrada < 8000000 || dni_entrada > 99999999){
		cout << "El DNI introducido no es válido. Se insertará un DNI aleatorio" << endl;
		//Implementar DNI aleatorio
	}
	else
		dni_ = dni_entrada;
}

dni::~dni(void){}

unsigned long int dni::get_dni(void){
	return dni_;
}

void dni::set_dni(unsigned long int dni_entrada){
	dni_ = dni_entrada;
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
