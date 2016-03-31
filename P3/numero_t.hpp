#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class numero_t{
public:
    virtual ostream& toStream(ostream& os) const=0;
    virtual istream& fromStream(istream& is)=0;
    friend std::ostream& operator<<(std::ostream& os, const numero_t& num);
	friend std::istream& operator>>(std::istream& is, numero_t& num);
};