#include "common.hpp"

#pragma once

using namespace std;

class dni{
private:
	unsigned long int dni_;
public:
	dni(void);
	dni(unsigned long int dni_entrada);
	~dni(void);
	unsigned long int get_dni(void);
	void set_dni(unsigned long int dni_entrada);
	void set_random(void);
	bool operator<(dni& dni_cp);
	bool operator>(dni& dni_cp);
	bool operator<=(dni& dni_cp);
	bool operator>=(dni& dni_cp);
};