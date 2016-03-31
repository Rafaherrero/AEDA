#pragma once
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "../numero_t.hpp"
#include "../excepciones.hpp"

#define INT_MIN_VAL -2147483647
#define INT_MAX_VAL 2147483647

class racional: public numero_t
{
public:
	long int numerador_;
	long int denominador_;
public:

	racional(void);
	racional(long long int numerador);
	racional(long long int numerador, long long int denominador);
	~racional(void);

	void simplify(void);
	int abs(int num);

	void set_numerador(long int numerador);
	void set_denominador(long int denominador);
	long int get_numerador(void);
	long int get_denominador(void);

	friend std::ostream& operator<<(std::ostream& os, const racional& num);
	friend std::istream& operator>>(std::istream& is, racional& num);

	ostream& toStream(ostream& os) const;
    istream& fromStream(istream& is);

	racional operator+(const racional& num) const;
	racional operator-(const racional& num) const;
	racional operator*(const racional& num) const;
	racional operator/(const racional& num) const;
};