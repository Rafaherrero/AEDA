#include "complejo.hpp"

complejo::complejo(void):
real_(0),
imag_(0){}

complejo::complejo(long double num):
imag_(0)
{
	set_real(num);
}

complejo::complejo(long double real, long double imag)
{
	set_real(real);
    set_imag(imag);
}

complejo::~complejo(void){}

void complejo::set_real(long double real){
	if(real < DOUBLE_MIN_VAL)
        throw exception::underflow_error("Exceeded 'DOUBLE_MIN_VAL'");
    if(real > DOUBLE_MAX_VAL)
        throw exception::overflow_error("Exceeded 'DOUBLE_MAX_VAL'");
    real_ = real;
}

void complejo::set_imag(long double imag){
	if(imag < DOUBLE_MIN_VAL)
        throw exception::underflow_error("Exceeded 'DOUBLE_MIN_VAL'");
    if(imag > DOUBLE_MAX_VAL)
        throw exception::overflow_error("Exceeded 'DOUBLE_MAX_VAL'");
    imag_ = imag;
}

long double complejo::get_real(void){
	return real_;
}

long double complejo::get_imag(void){
	return imag_;
}

std::ostream& operator<<(std::ostream& os, const complejo& num)
{
	if(num.imag_>=0){os << num.real_ << " + " << num.imag_ << "i"; return os;}
 	os << num.real_ << " - " << num.imag_ << "i"; return os;
}
std::istream& operator>>(std::istream& is, complejo& num){	is >> num.real_ >> num.imag_; return is;}

ostream& complejo::toStream(ostream& os) const
{
    if(imag_>=0)
        os << real_ << " + " << imag_ << "i";
    else
	    os << real_ << " - " << imag_ << "i";
	return os;
}

istream& complejo::fromStream(istream& is)
{
    is >> real_ >> imag_;
    return is;
}

complejo complejo::operator+(const complejo& num) const
{
	return complejo(real_ + num.real_, imag_ + num.imag_);
}

complejo complejo::operator-(const complejo& num) const
{
	return complejo(real_ - num.real_, imag_ - num.imag_);
}

complejo complejo::operator*(const complejo& num) const
{
	return complejo(((real_ * num.real_) - (imag_ * num.imag_)), ((imag_ * num.real_) + (real_ * num.imag_)));
}

complejo complejo::operator/(const complejo& num) const
{
	return complejo( ( (real_ * num.real_) - (imag_ * num.imag_) )/( num.real_*num.real_ + num.imag_*num.imag_ ), ( (imag_ * num.real_) + (real_ * num.imag_) )/( num.real_*num.real_ + num.imag_*num.imag_ ) );
}

const entero complejo::toEntero() const{
	//throw exception::error_precision("Error en la precision");
    return entero(int(real_));
}
const racional complejo::toRacional() const{
	//throw exception::error_precision("Error en la precision");
    return racional(int(real_));
}
const real complejo::toReal() const{
	//throw exception::error_precision("Error en la precision");
    return real(double(real_));
}
const complejo complejo::toComplejo() const{
    return complejo(real_,imag_);
}