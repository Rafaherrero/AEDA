#include "racional.hpp"

racional::racional(void):
numerador_(0),
denominador_(1){}

racional::racional(long long int numerador):
numerador_(0),
denominador_(1)
{
	set_numerador(numerador);
}

racional::racional(long long int numerador, long long int denominador)
{
	set_numerador(numerador);
	
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

void racional::set_numerador(long long int numerador)
{
	if(numerador < INT_MIN_VAL)
        throw exception::underflow_error("Exceeded 'INT_MIN_VAL'");
    if(numerador > INT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'INT_MAX_VAL'");
	numerador_ = numerador;
	simplify();
}

void racional::set_denominador(long long int denominador)
{
	if(denominador == 0)
        throw exception::out_of_range("0 in denominator");
	denominador_ = denominador;
	simplify();
}

long int racional::get_numerador(void){return numerador_;}
long int racional::get_denominador(void){return denominador_;}

ostream& racional::toStream(ostream& os) const
{
    os << numerador_ << "/" << denominador_;
    return os;
}

istream& racional::fromStream(istream& is)
{
    is >> numerador_ >> denominador_;
    return is;
}

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

const entero racional::toEntero() const{
	//throw exception::error_precision("Error en la precision");
    return entero(int(numerador_/denominador_));
}
const racional racional::toRacional() const{
    return racional(numerador_,denominador_);
}
const real racional::toReal() const{
    return real(double(numerador_/denominador_));
}
const complejo racional::toComplejo() const{
	//throw exception::error_precision("Error en la precision");
    return complejo((numerador_/denominador_),1);
}