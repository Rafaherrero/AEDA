#include "common.h"

template<class tipo_dato>
class node{
private:
	tipo_dato dato_;
	nodo* izquierda_;
	nodo* derecha_;
public:
	nodo(void);
	nodo(tipo_dato dato);
	~nodo(void);
	nodo*& izquierda(void);
	nodo*& derecha(void);
	tipo_dato& dato(void);
};

template<class tipo_dato>
nodo<tipo_dato>::nodo(void):
dato_(),
izquierda_(nullptr),
derecha_(nullptr)
{}

template<class tipo_dato>
nodo<tipo_dato>::nodo(tipo_dato dato):
dato_(data),
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