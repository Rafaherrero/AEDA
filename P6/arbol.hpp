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
	unsigned insert(tipo_dato elemento);
	unsigned insert(nodo<tipo_dato>* nodo_, nodo<tipo_dato>*& raiz, unsigned ct_cp);

	void imprimir_dato(nodo<tipo_dato>* nodo);
	void pre_orden(void);
	void post_orden(void);
	void in_orden(void);
	void pre_orden(nodo<tipo_dato>* raiz);
	void post_orden(nodo<tipo_dato>* raiz);
	void in_orden(nodo<tipo_dato>* raiz);

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

template<class tipo_dato>
unsigned arbol<tipo_dato>::insert(tipo_dato elemento)
{
    nodo<tipo_dato>* nodo_ = new nodo<tipo_dato>(elemento);
    return insert(nodo_, raiz_, 0);
}

template<class tipo_dato>
unsigned arbol<tipo_dato>::insert(nodo<tipo_dato>* nodo_, nodo<tipo_dato>*& raiz, unsigned ct_cp)
{
    ct_cp++;
	if(raiz == nullptr){
		raiz = nodo_;
		return ct_cp;
	}
	if(nodo_->dato() <= raiz->dato())
		ct_cp = insert(nodo_, raiz->izquierda(), ct_cp);
	else
		ct_cp = insert(nodo_, raiz->derecha(), ct_cp);
	
	return ct_cp;
}

template<class tipo_dato>
void arbol<tipo_dato>::imprimir_dato(nodo<tipo_dato>* nodo)
{
    if(nodo == nullptr){
        cout << "--";
        return;
    }
	cout << nodo->dato() << " ";
}

template<class tipo_dato>
void arbol<tipo_dato>::pre_orden(void)
{
    pre_orden(raiz_);
}

template<class tipo_dato>
void arbol<tipo_dato>::post_orden(void)
{
    post_orden(raiz_);
}

template<class tipo_dato>
void arbol<tipo_dato>::in_orden(void)
{
    in_orden(raiz_);
}
template<class tipo_dato>
void arbol<tipo_dato>::pre_orden(nodo<tipo_dato>* raiz)
{
    if(raiz == nullptr)
        return;
    imprimir_dato(raiz);
    pre_orden(raiz->izquierda());
    pre_orden(raiz->derecha());
}

template<class tipo_dato>
void arbol<tipo_dato>::post_orden(nodo<tipo_dato>* raiz)
{
    if(raiz == nullptr)
        return;
    post_orden(raiz->izquierda());
    post_orden(raiz->derecha());
    imprimir_dato(raiz);
}

template<class tipo_dato>
void arbol<tipo_dato>::in_orden(nodo<tipo_dato>* raiz)
{
    if(raiz == nullptr)
        return;
    in_orden(raiz->izquierda());
    imprimir_dato(raiz);
    in_orden(raiz->derecha());
}