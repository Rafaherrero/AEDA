#include "entero.hpp"

entero::entero(void):
number_(0)
{}

entero::entero(long long int num):
number_(0)
{
    if(num < INT_MIN_VAL)
        throw exception::underflow_error("Exceeded 'INT_MIN_VAL'");
    if(num > INT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'INT_MAX_VAL'");
    number_ = num;
}

entero::entero(const entero& intg)
{
    number_ = intg.number_;
}

entero::~entero(void)
{}

entero entero::operator+(const entero& intg) const
{
    if((number_ + intg.number_) > INT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'INT_MAX_VAL' in operator '+'");
    return number_ + intg.number_;
}

entero entero::operator-(const entero& intg) const
{
    if((number_ - intg.number_) < INT_MIN_VAL)
        throw exception::underflow_error("Exceeded 'INT_MIN_VAL'");
    return number_ - intg.number_;
}

entero entero::operator*(const entero& intg) const
{
    if((number_ * intg.number_) > INT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'INT_MAX_VAL' in operator '*'");
    return number_ * intg.number_;
}

entero entero::operator/(const entero& intg) const
{
    if(intg.number_ == 0)
        throw exception::out_of_range("0 in denominator");
    return number_ / intg.number_;
}

ostream& entero::toStream(ostream& os) const
{
    os << number_;
    return os;
}

istream& entero::fromStream(istream& is)
{
    is >> number_;
    return is;
}

ostream& operator<<(ostream& os, const entero& intg)
{
    os << intg.number_;
    return os;
}

istream& operator>>(istream& is, entero& intg)
{
    is >> intg.number_;
    return is;
}