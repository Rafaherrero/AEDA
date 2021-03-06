#pragma once
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <unistd.h>
#include "../Complejo/complejo.hpp"
#include "../Entero/entero.hpp"
#include "../Racional/racional.hpp"
#include "../numero_t.hpp"
#include "../excepciones.hpp"

#define REL_MIN_VAL -1.0e308
#define REL_MAX_VAL 1.0e308

using namespace std;

class real: public numero_t{
private:
    double number_;
public:

    real(void);
    real(long double);
    real(const real&);
    ~real(void);

    real operator+(const real& rel) const;
    real operator-(const real& rel) const;
    real operator*(const real& rel) const;
    real operator/(const real& rel) const;

    const entero toEntero() const;
    const racional toRacional() const;
    const real toReal() const;
    const complejo toComplejo() const;

    friend ostream& operator<<(ostream& os, const real& rel);
    friend istream& operator>>(istream& is, real& rel);

    ostream& toStream(ostream& os) const;
    istream& fromStream(istream& is);
};