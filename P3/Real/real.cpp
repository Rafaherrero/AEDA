#include "real.hpp"

real::real(void):
number_(0)
{}

real::real(long double num):
number_(0)
{
    if(num < REL_MIN_VAL)
        throw exception::underflow_error("Exceeded 'REL_MIN_VAL'");
    if(num > REL_MAX_VAL)
        throw exception::overflow_error("Exceeded 'REL_MAX_VAL'");
    number_ = num;
}

real::real(const real& rel)
{
    number_ = rel.number_;
}

real::~real(void)
{}

real real::operator+(const real& rel) const
{
    if((number_ + rel.number_) > REL_MAX_VAL)
        throw exception::overflow_error("Exceeded 'REL_MAX_VAL' in operator '+'");
    return number_ + rel.number_;
}

real real::operator-(const real& rel) const
{
    if((number_ - rel.number_) < REL_MIN_VAL)
        throw exception::underflow_error("Exceeded 'REL_MIN_VAL'");
    return number_ - rel.number_;
}

real real::operator*(const real& rel) const
{
    if((number_ * rel.number_) > REL_MAX_VAL)
        throw exception::overflow_error("Exceeded 'REL_MAX_VAL' in operator '*'");
    return number_ * rel.number_;
}

real real::operator/(const real& rel) const
{
    if(rel.number_ == 0)
        throw exception::out_of_range("0 in denominator");
    return number_ / rel.number_;
}

ostream& real::toStream(ostream& os) const
{
    os << number_;
    return os;
}

istream& real::fromStream(istream& is)
{
    is >> number_;
    return is;
}

ostream& operator<<(ostream& os, const real& rel)
{
    rel.toStream(os);
    return os;
}

istream& operator>>(istream& is, real& rel)
{
    rel.fromStream(is);
    return is;
}

const entero real::toEntero() const{
	//throw exception::error_precision("Error en la precision");
    return entero(int(number_));
}
const racional real::toRacional() const{
	//throw exception::error_precision("Error en la precision");
    return racional(int(number_));
}
const real real::toReal() const{
    return real(number_);
}
const complejo real::toComplejo() const{
	//throw exception::error_precision("Error en la precision");
    return complejo(number_,1);
}