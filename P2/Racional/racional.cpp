#include "racional.hpp"

racional::racional(void):
numerador_(0),
denominador_(1){}

racional::racional(int numerador):
numerador_(numerador),
denominador_(1){}

racional::racional(int numerador, int denominador):
numerador_(numerador)
{
	set_denominador(denominador);
}

racional::~racional(void){}

void racional::simplify(void)
{
	for(int i = abs(numerador_ * denominador_); i > 1; i = i - 1){
		if((denominador_ % i == 0) && (numerador_ % i == 0)){
			denominador_ = denominador_ / i;
			numerador_   = numerador_   / i;
		}
	}
}

int racional::abs(int num)
{
	if(num < 0)
		return num*-1;
	return num;
}

void racional::set_numerador(int numerador)
{
	numerador_ = numerador;
	simplify();
}

void racional::set_denominador(int denominador)
{
	if(denominador == 0) exit(1);
	else denominador_ = denominador;
	simplify();
}

int racional::get_numerador(void){return numerador_;}
int racional::get_denominador(void){return denominador_;}

std::ostream& operator<<(std::ostream& os, const racional& num){ os << num.numerador_ << "/" << num.denominador_; return os;}
std::istream& operator>>(std::istream& is, racional& num){ is >> num.numerador_ >> num.denominador_; return is;}


racional racional::operator+(const racional& num) const
{
	racional aux((numerador_ * num.denominador_) + (num.numerador_ * denominador_), denominador_*num.denominador_);
	aux.simplify();
	return aux;
}

racional racional::operator-(const racional& num) const
{
	racional aux(num.numerador_*-1, num.denominador_);
	aux = aux + *this;
	return aux;
}


racional racional::operator*(const racional& num) const
{
	racional aux(numerador_*num.numerador_, denominador_*num.denominador_);
	aux.simplify();
	return aux;
}

racional racional::operator/(const racional& num) const
{
	racional aux(numerador_*num.denominador_, denominador_*num.numerador_);
	aux.simplify();
	return aux;
}