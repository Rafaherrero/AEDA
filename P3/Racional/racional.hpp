#pragma once
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "../numero_t.hpp"

class racional: public numero_t
{
public:
	int numerador_;
	int denominador_;
public:

	racional(void);
	racional(int numerador);
	racional(int numerador, int denominador);
	~racional(void);

	void simplify(void);
	int abs(int num);

	void set_numerador(int numerador);
	void set_denominador(int denominador);
	int get_numerador(void);
	int get_denominador(void);

	friend std::ostream& operator<<(std::ostream& os, const racional& num);
	friend std::istream& operator>>(std::istream& is, racional& num);

	ostream& toStream(ostream& os) const;
    istream& fromStream(istream& is);

	racional operator+(const racional& num) const;
	racional operator-(const racional& num) const;
	racional operator*(const racional& num) const;
	racional operator/(const racional& num) const;
};