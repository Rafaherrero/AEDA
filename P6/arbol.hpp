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
	bool empty(void) const;
	bool empty(nodo<tipo_dato>* nodo) const;
	unsigned size(void) const;
	unsigned size(nodo<tipo_dato>* nodo) const;

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

template<class tipo_dato>
bool arbol<tipo_dato>::empty(void) const
{
    return empty(raiz_);
}

template<class tipo_dato>
bool arbol<tipo_dato>::empty(nodo<tipo_dato>* nodo) const
{
    return nodo == nullptr;
}

template<class tipo_dato>
unsigned arbol<tipo_dato>::size(void) const
{
    return size(raiz_);
}

template<class tipo_dato>
unsigned arbol<tipo_dato>::size(nodo<tipo_dato>* nodo) const
{
    if(empty(nodo))
        return 0;
    return(1 + size(nodo->izquierda()) + size(nodo->derecha()));
}