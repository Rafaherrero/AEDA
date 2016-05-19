#include "common.hpp"

#pragma once

template<class tipo_dato>
class nodo{
private:
	tipo_dato dato_;
	nodo* izquierda_;
	nodo* derecha_;
	int bal_;
public:
	nodo(void);
	nodo(tipo_dato dato);
	~nodo(void);
	nodo*& izquierda(void);
	nodo*& derecha(void);
	tipo_dato& dato(void);
	int& bal(void);
};

template<class tipo_dato>
nodo<tipo_dato>::nodo(void):
dato_(),
bal_(0),
izquierda_(nullptr),
derecha_(nullptr)
{}

template<class tipo_dato>
nodo<tipo_dato>::nodo(tipo_dato dato):
dato_(dato),
bal_(0),
izquierda_(nullptr),
derecha_(nullptr)
{}

template<class tipo_dato>
nodo<tipo_dato>::~nodo(void){}

template<class tipo_dato>
nodo<tipo_dato>*& nodo<tipo_dato>::derecha(void){
	return derecha_;
}

template<class tipo_dato>
nodo<tipo_dato>*& nodo<tipo_dato>::izquierda(void){
	return izquierda_;
}

template<class tipo_dato>
tipo_dato& nodo<tipo_dato>::dato(void){
	return dato_;
}

template<class tipo_dato>
int& nodo<tipo_dato>::bal(void){
	return bal_;
}