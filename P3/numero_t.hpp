#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class entero;
class racional;
class real;
class complejo;

class numero_t{
public:
    virtual ostream& toStream(ostream& os) const=0;
    virtual istream& fromStream(istream& is)=0;
    
	virtual const entero toEntero() const = 0;
	virtual const racional toRacional() const = 0;
	virtual const real toReal() const = 0;
	virtual const complejo toComplejo() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const numero_t& num);
	friend std::istream& operator>>(std::istream& is, numero_t& num);
};