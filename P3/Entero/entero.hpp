#pragma once
#include <iostream>
#include <ostream>
#include <iomanip>
#include <cstdlib>
#include "../Complejo/complejo.hpp"
#include "../Real/real.hpp"
#include "../Racional/racional.hpp"
#include "../numero_t.hpp"
#include "../excepciones.hpp"

#define INT_MIN_VAL -2147483647
#define INT_MAX_VAL 2147483647

using namespace std;

class entero: public numero_t
{
private:
    long int number_;
public:
    
    entero(void);
    entero(long long int);
    entero(const entero&);
    ~entero(void);
    
    entero operator+(const entero& intg) const;
    entero operator-(const entero& intg) const;
    entero operator*(const entero& intg) const;
    entero operator/(const entero& intg) const;

    const entero toEntero() const;
    const racional toRacional() const;
    const real toReal() const;
    const complejo toComplejo() const;

    friend ostream& operator<<(ostream& os, const entero& num);
    friend istream& operator>>(istream& is, entero& num);
    
    ostream& toStream(ostream& os) const;
    istream& fromStream(istream& is);
};