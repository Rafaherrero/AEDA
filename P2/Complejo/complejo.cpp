#include "complejo.hpp"

complejo::complejo(void):
real_(0),
imag_(0){}

complejo::complejo(long double num):
real_(num),
imag_(0){}

complejo::complejo(long double real, long double imag):
real_(real),
imag_(imag){}

complejo::~complejo(void){}

void complejo::set_real(long double real){real_ = real;}
void complejo::set_imag(long double imag){imag_ = imag;}
long double complejo::get_real(void){return real_;}
long double complejo::get_imag(void){return imag_;}

std::ostream& operator<<(std::ostream& os, const complejo& num)
{
	if(num.imag_>=0){os << num.real_ << " + " << num.imag_ << "i"; return os;}
	os << num.real_ << " - " << num.imag_ << "i"; return os;
}
std::istream& operator>>(std::istream& is, complejo& num){	is >> num.real_ >> num.imag_; return is;}


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
	complejo aux( ( (real_ * num.real_) - (imag_ * num.imag_) )/( num.real_*num.real_ + num.imag_*num.imag_ ), ( (imag_ * num.real_) + (real_ * num.imag_) )/( num.real_*num.real_ + num.imag_*num.imag_ ) );
}
