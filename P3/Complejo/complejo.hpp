#pragma once
#include <iostream>
#include <ostream>
#include <iomanip>
#include <cstdlib>
#include "../numero_t.hpp"
#include "../excepciones.hpp"

#define DOUBLE_MIN_VAL -1.0e308
#define DOUBLE_MAX_VAL 1.0e308

using namespace std;

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
	
	friend ostream& operator<<(ostream& os, const complejo& num);
	friend istream& operator>>(istream& is, complejo& num);

	ostream& toStream(ostream& os) const;
    istream& fromStream(istream& is);

	complejo operator+(const complejo& num) const;
	complejo operator-(const complejo& num) const;
	complejo operator*(const complejo& num) const;
	complejo operator/(const complejo& num) const;

};