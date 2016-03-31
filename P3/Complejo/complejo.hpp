#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "../numero_t.hpp"

class complejo: public numero_t
{
private:
	long double real_;
	long double imag_;
public:

	complejo(void);
	complejo(long double);
	complejo(long double, long double);
	~complejo(void);

	void set_real(long double real);
	void set_imag(long double imag);
	long double get_real(void);
	long double get_imag(void);
	
	friend std::ostream& operator<<(std::ostream& os, const complejo& num);
	friend std::istream& operator>>(std::istream& is, complejo& num);

	ostream& toStream(ostream& os) const;
    istream& fromStream(istream& is);

	complejo operator+(const complejo& num) const;
	complejo operator-(const complejo& num) const;
	complejo operator*(const complejo& num) const;
	complejo operator/(const complejo& num) const;

};