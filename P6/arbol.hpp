#include "nodo.hpp"

#pragma once

template<class tipo_dato>
class arbol{
private:
	nodo<tipo_dato>* raiz_;
public:
	arbol(void);
	arbol(nodo<tipo_dato>* nodo_raiz);
	~arbol(void);
	nodo<tipo_dato>* get_raiz(void);

};

template<class tipo_dato>
arbol<tipo_dato>::arbol (void):
raiz_(nullptr)
{}

template<class tipo_dato>
arbol<tipo_dato>::arbol (nodo<tipo_dato>* nodo_raiz):
raiz_(nodo_raiz)
{}

template<class tipo_dato>
arbol<tipo_dato>::~arbol(void){}

template<class tipo_dato>
nodo<tipo_dato>* arbol<tipo_dato>::get_raiz(void){
	return raiz_;
}