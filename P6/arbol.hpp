#include "nodo.hpp"

#pragma once
using namespace std;

template<class tipo_dato>
class arbol{
private:
	nodo<tipo_dato>* raiz_;
	unsigned cp_esta;
public:
	arbol(void);
	arbol(nodo<tipo_dato>* nodo_raiz);
	~arbol(void);
	void podar(nodo<tipo_dato>*& nodo_);

	nodo<tipo_dato>* get_raiz(void);
	bool empty(void) const;
	bool empty(nodo<tipo_dato>* nodo) const;
	unsigned size(void) const;
	unsigned size(nodo<tipo_dato>* nodo) const;
	unsigned height(void) const;
	unsigned height(nodo<tipo_dato>* nodo) const;
	bool leaf(nodo<tipo_dato>* nodo);

	unsigned insertar(tipo_dato elemento);
	unsigned insertar(nodo<tipo_dato>* nodo_, nodo<tipo_dato>*& raiz, unsigned ct_cp);
	void eliminar(tipo_dato elemento);
	void eliminar(tipo_dato elemento, nodo<tipo_dato>*& raiz);
	void sustituir(nodo<tipo_dato>*& viejo, nodo<tipo_dato>*& cambio);
	nodo<tipo_dato>* buscar(tipo_dato elemento);
	nodo<tipo_dato>* buscar(nodo<tipo_dato>* nodo, tipo_dato elemento);

	void imprimir_dato(nodo<tipo_dato>* nodo);
	void pre_orden(void);
	void post_orden(void);
	void in_orden(void);
	void nivel_orden(void);
	void pre_orden(nodo<tipo_dato>* raiz);
	void post_orden(nodo<tipo_dato>* raiz);
	void in_orden(nodo<tipo_dato>* raiz);
	void nivel_orden(nodo<tipo_dato>* raiz);

	unsigned get_esta(void);
};

template<class tipo_dato>
arbol<tipo_dato>::arbol (void):
raiz_(nullptr),
cp_esta(0)
{}

template<class tipo_dato>
arbol<tipo_dato>::arbol (nodo<tipo_dato>* nodo_raiz):
raiz_(nodo_raiz),
cp_esta(0)
{}

template<class tipo_dato>
arbol<tipo_dato>::~arbol(void){
	podar(raiz_);
}

template<class tipo_dato>
void arbol<tipo_dato>::podar(nodo<tipo_dato>*& nodo_) {

	if (empty(nodo_)) 
		return;
	podar(nodo_->izquierda());
	podar(nodo_->derecha());

	nodo_ = nullptr;
}

template<class tipo_dato>
nodo<tipo_dato>* arbol<tipo_dato>::get_raiz(void){
	return raiz_;
}

template<class tipo_dato>
bool arbol<tipo_dato>::empty(void) const{
    return empty(raiz_);
}

template<class tipo_dato>
bool arbol<tipo_dato>::empty(nodo<tipo_dato>* nodo) const{
    return nodo == nullptr;
}

template<class tipo_dato>
unsigned arbol<tipo_dato>::size(void) const{
    return size(raiz_);
}

template<class tipo_dato>
unsigned arbol<tipo_dato>::size(nodo<tipo_dato>* nodo) const{
    if(empty(nodo))
        return 0;
    return(1 + size(nodo->izquierda()) + size(nodo->derecha()));
}

template<class tipo_dato>
unsigned arbol<tipo_dato>::height(void) const
{
    return height(raiz_);
}

template<class tipo_dato>
unsigned arbol<tipo_dato>::height(nodo<tipo_dato>* nodo) const
{
    if(nodo == nullptr)
        return 0;

    return max(height(nodo->izquierda()), height(nodo->derecha()))+1;
}

template<class tipo_dato>
bool arbol<tipo_dato>::leaf(nodo<tipo_dato>* nodo){
	return !nodo->derecha() && !nodo->izquierda();
}

template<class tipo_dato>
unsigned arbol<tipo_dato>::insertar(tipo_dato elemento){
    nodo<tipo_dato>* nodo_ = new nodo<tipo_dato>(elemento);
    return insertar(nodo_, raiz_, 0);
}

template<class tipo_dato>
unsigned arbol<tipo_dato>::insertar(nodo<tipo_dato>* nodo_, nodo<tipo_dato>*& raiz, unsigned ct_cp){
    ct_cp++;
	if(raiz == nullptr){
		raiz = nodo_;
		return ct_cp;
	}
	if(nodo_->dato() <= raiz->dato())
		ct_cp = insertar(nodo_, raiz->izquierda(), ct_cp);
	else
		ct_cp = insertar(nodo_, raiz->derecha(), ct_cp);
	
	return ct_cp;
}

template<class tipo_dato>
void arbol<tipo_dato>::eliminar(tipo_dato elemento){
    eliminar(elemento, raiz_);
}

template<class tipo_dato>
void arbol<tipo_dato>::eliminar(tipo_dato elemento, nodo<tipo_dato>*& raiz){
    if(raiz == nullptr)
        return;

    if(elemento < raiz->dato())
        eliminar(elemento, raiz->izquierda());
    else if(elemento > raiz->dato())
        eliminar(elemento, raiz->derecha());
    else{
        nodo<tipo_dato>* viejo = raiz;

        if(raiz->derecha() == nullptr)
            raiz = raiz->izquierda();
        else if(raiz->izquierda() == nullptr)
            raiz = raiz->derecha();
        else
            sustituir(viejo, raiz->izquierda());

        delete viejo;
    }
}

template<class tipo_dato>
void arbol<tipo_dato>::sustituir(nodo<tipo_dato>*& viejo, nodo<tipo_dato>*& cambio){
    if(cambio->derecha() != nullptr)
        sustituir(viejo, cambio->derecha());
    else{
        viejo->dato() = cambio->dato();
        viejo = cambio;
        cambio = cambio->izquierda();
    }
}

template<class tipo_dato>
void arbol<tipo_dato>::imprimir_dato(nodo<tipo_dato>* nodo){
    if(nodo == nullptr){
        cout << "[.]";
        return;
    }
	cout << nodo->dato() << " ";
}

template<class tipo_dato>
void arbol<tipo_dato>::pre_orden(void){
    pre_orden(raiz_);
}

template<class tipo_dato>
void arbol<tipo_dato>::post_orden(void){
    post_orden(raiz_);
}

template<class tipo_dato>
void arbol<tipo_dato>::in_orden(void){
    in_orden(raiz_);
}

template<class tipo_dato>
void arbol<tipo_dato>::nivel_orden(void){
	nivel_orden(raiz_);
}

template<class tipo_dato>
void arbol<tipo_dato>::pre_orden(nodo<tipo_dato>* raiz){
    if(raiz == nullptr)
        return;
    imprimir_dato(raiz);
    pre_orden(raiz->izquierda());
    pre_orden(raiz->derecha());
}

template<class tipo_dato>
void arbol<tipo_dato>::post_orden(nodo<tipo_dato>* raiz){
    if(raiz == nullptr)
        return;
    post_orden(raiz->izquierda());
    post_orden(raiz->derecha());
    imprimir_dato(raiz);
}

template<class tipo_dato>
void arbol<tipo_dato>::in_orden(nodo<tipo_dato>* raiz){
    if(raiz == nullptr)
        return;
    in_orden(raiz->izquierda());
    imprimir_dato(raiz);
    in_orden(raiz->derecha());
}

template<class tipo_dato>
void arbol<tipo_dato>::nivel_orden(nodo<tipo_dato>* raiz){
	deque<pair<nodo<tipo_dato>*, unsigned>> cola;
	nodo<tipo_dato>* copia_nodo;
	unsigned nivel = 0, nivel_actual = 0;

	cola.push_back(pair<nodo<tipo_dato>*, unsigned>(raiz,0));

	cout << "Nivel 0: ";
	while(!cola.empty()){
		copia_nodo = get<0>(cola.front());
        nivel = get<1>(cola.front());
		cola.pop_front();
		if(nivel > nivel_actual){
			nivel_actual = nivel;
			cout << endl << "Nivel " << nivel_actual << ": ";
		}

		if (copia_nodo != nullptr){
			imprimir_dato(copia_nodo);
			cola.push_back(pair<nodo<tipo_dato>*, unsigned>(copia_nodo -> izquierda(), nivel+1));
			cola.push_back(pair<nodo<tipo_dato>*, unsigned>(copia_nodo -> derecha(), nivel+1));
		}
		else{
			imprimir_dato(nullptr);
		}

	}
}

template<class tipo_dato>
nodo<tipo_dato>* arbol<tipo_dato>::buscar(tipo_dato elemento){
	cp_esta = 0; 
	return buscar(raiz_, elemento);
}

template<class tipo_dato>
nodo<tipo_dato>* arbol<tipo_dato>::buscar(nodo<tipo_dato>* nodo, tipo_dato elemento){

	if (nodo == nullptr){
		cp_esta ++;
		return nullptr;
	}

	if (elemento == nodo->dato()){
		cp_esta ++;
		return nodo;
	}

	if (elemento < nodo->dato()){
		cp_esta ++;
		return buscar(nodo->izquierda(), elemento);
	}
	return buscar(nodo->derecha(), elemento);
}

template<class tipo_dato>
unsigned arbol<tipo_dato>::get_esta(void){
	return cp_esta;
}