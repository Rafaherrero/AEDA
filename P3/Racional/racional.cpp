#include "racional.hpp"

racional::racional(void):
numerador_(0),
denominador_(1){}

racional::racional(long long int numerador):
numerador_(0),
denominador_(1)
{
	if(numerador < INT_MIN_VAL)
        throw exception::underflow_error("Exceeded 'INT_MIN_VAL'");
    if(numerador > INT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'INT_MAX_VAL'");
}

racional::racional(long long int numerador, long long int denominador):
numerador_(0)
{
	if(numerador < INT_MIN_VAL)
        throw exception::underflow_error("Exceeded 'INT_MIN_VAL'");
    if(numerador > INT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'INT_MAX_VAL'");
    numerador_ = numerador;
	
	if(denominador < INT_MIN_VAL)
        throw exception::underflow_error("Exceeded 'INT_MIN_VAL'");
    if(denominador > INT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'INT_MAX_VAL'");
    if(denominador == 0)
        throw exception::out_of_range("0 in denominator");
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

void racional::set_numerador(long int numerador)
{
	if(numerador < INT_MIN_VAL)
        throw exception::underflow_error("Exceeded 'INT_MIN_VAL'");
    if(numerador > INT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'INT_MAX_VAL'");
	numerador_ = numerador;
	simplify();
}

void racional::set_denominador(long int denominador)
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