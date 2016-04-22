#include "dni.hpp"

dni::dni(void):
	dni_(0)
{}

dni::dni(unsigned long int dni_entrada):
	dni_(dni_entrada)
{}

dni::~dni(void){}

unsigned long int dni::get_dni(void){
	return dni_;
}

void dni::set_dni(unsigned long int dni_entrada){
	dni_ = dni_entrada;
}