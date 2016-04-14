#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "clave.cpp"
#include "celda.cpp"
pragma once;

using namespace std;

class tabla_hash<class clave>{
private:
	unsigned ct_celdas_;
	unsigned ct_registros_;
	unsigned funcion_hash_;
public:
	tabla_hash(void);
	tabla_hash(unsigned celdas, unsigned resgistros, unsigned funcion);
	~tabla_hash(void);
}