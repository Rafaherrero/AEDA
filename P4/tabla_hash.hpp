#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <vector>

#include "celda.hpp"
#pragma once

using namespace std;

template<class tipo_clave>
class tabla_hash{
private:
	unsigned ct_celdas_;
	unsigned ct_registros_;
	unsigned funcion_hash_;
	vector<celda<tipo_clave>>* tabla_;
public:
	tabla_hash(void);
	tabla_hash(unsigned celdas, unsigned registros, unsigned funcion);
	~tabla_hash(void);
	unsigned hash(tipo_clave* cv);
    unsigned hash_module(tipo_clave* cv);
    unsigned hash_pseudo_random(tipo_clave* cv);

    void insertar(tipo_clave* cv);
};

template<class tipo_clave>
tabla_hash<tipo_clave>::tabla_hash(void):
ct_celdas_(0),
ct_registros_(0),
funcion_hash_(0)
{}

template<class tipo_clave>
tabla_hash<tipo_clave>::tabla_hash(unsigned celdas, unsigned registros, unsigned funcion):
ct_celdas_(celdas),
ct_registros_(registros),
funcion_hash_(funcion),
{
	tabla_ = new vector*<celda<tipo_clave>>(ct_celdas_);
    for(int i = 0; i < ct_celdas_; i++)
        tabla_[i] = celda<tipo_clave>(ct_registros_);
}

template<class tipo_clave>
tabla_hash<tipo_clave>::~tabla_hash(void){
}

template<class tipo_clave>
unsigned tabla_hash<tipo_clave>::hash(tipo_clave* cv){
	if(funcion_hash_==1)
		hash_module(cv);
	else if (funcion_hash_==2)
		hash_pseudo_random(cv);
	else
		cout << "Error en la función de selección" << endl;
}

template<class tipo_clave>
unsigned tabla_hash<tipo_clave>::hash_module(tipo_clave* cv){
	return cv % ct_celdas_;
}

template<class tipo_clave>
unsigned tabla_hash<tipo_clave>::hash_pseudo_random(tipo_clave* cv){
	srand(cv);
    return rand() % ct_celdas_;
}

template<class tipo_clave>
void tabla_hash<tipo_clave>::insertar(tipo_clave* cv){

	tabla_[hash(cv)].insertar(cv);
	if(true){
		cout << "No se ha podido insertar la clave a la primera." << endl;

	}
}