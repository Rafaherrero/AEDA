#include <iostream>
#include <cstdlib>
#include <time.h>
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
	bool operator<(dni& dni_cp);
	bool operator>(dni& dni_cp);
	bool operator<=(dni& dni_cp);
	bool operator>=(dni& dni_cp);
};