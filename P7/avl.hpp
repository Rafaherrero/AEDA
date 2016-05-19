#include "nodo.hpp"

#pragma once
using namespace std;

template<class tipo_dato>
class avl{
private:
	nodo<tipo_dato>* raiz_;
	unsigned cp_esta;
public:
	avl(void);
	avl(nodo<tipo_dato>* nodo_raiz);
	~avl(void);
	void podar(nodo<tipo_dato>*& nodo_);

	nodo<tipo_dato>* get_raiz(void);
	bool empty(void) const;
	bool empty(nodo<tipo_dato>* nodo) const;
	unsigned size(void) const;
	unsigned size(nodo<tipo_dato>* nodo) const;
	unsigned height(void) const;
	unsigned height(nodo<tipo_dato>* nodo) const;
	bool leaf(nodo<tipo_dato>* nodo);

	void sustituir(nodo<tipo_dato>*& viejo, nodo<tipo_dato>*& cambio, bool &decrece);

	void imprimir_dato(nodo<tipo_dato>* nodo);
	void nivel_orden(void);
	void nivel_orden(nodo<tipo_dato>* raiz);
	nodo<tipo_dato>* buscar(tipo_dato elemento);
	nodo<tipo_dato>* buscar(nodo<tipo_dato>* nodo, tipo_dato elemento);

	unsigned get_esta(void);

	bool balanceado(void);
	bool balanceado(nodo<tipo_dato>* nodo_pasado);
	void rotacion_II(nodo<tipo_dato>*& nodo_pasado);
	void rotacion_DD(nodo<tipo_dato>*& nodo_pasado);
	void rotacion_ID(nodo<tipo_dato>*& nodo_pasado);
	void rotacion_DI(nodo<tipo_dato>*& nodo_pasado);

	void insertar(tipo_dato elemento);
	void insertar_bal(nodo<tipo_dato>* &nodo_pasado, nodo<tipo_dato>* nuevo, bool& crece);
	void insertar_rebalancea_izquierda(nodo<tipo_dato>* &nodo_pasado, bool &crece);
	void insertar_rebalancea_derecha(nodo<tipo_dato>* &nodo_pasado, bool &crece);
	void eliminar(tipo_dato elemento);
	void eliminar_rama(nodo<tipo_dato>* &nodo_pasado, tipo_dato elemento, bool &decrece);
	void eliminar_rebalancea_izquierda(nodo<tipo_dato>* &nodo_pasado, bool &decrece);
	void eliminar_rebalancea_derecha(nodo<tipo_dato>* &nodo_pasado, bool &decrece);
	void sustituye(nodo<tipo_dato>* &eliminado, nodo<tipo_dato>* &sust, bool &decrece);
};

template<class tipo_dato>
avl<tipo_dato>::avl (void):
raiz_(nullptr),
cp_esta(0)
{}

template<class tipo_dato>
avl<tipo_dato>::avl (nodo<tipo_dato>* nodo_raiz):
raiz_(nodo_raiz),
cp_esta(0)
{}

template<class tipo_dato>
avl<tipo_dato>::~avl(void){
	podar(raiz_);
}

template<class tipo_dato>
void avl<tipo_dato>::podar(nodo<tipo_dato>*& nodo_) {

	if (empty(nodo_)) 
		return;
	podar(nodo_->izquierda());
	podar(nodo_->derecha());

	nodo_ = nullptr;
}

template<class tipo_dato>
nodo<tipo_dato>* avl<tipo_dato>::get_raiz(void){
	return raiz_;
}

template<class tipo_dato>
bool avl<tipo_dato>::empty(void) const{
    return empty(raiz_);
}

template<class tipo_dato>
bool avl<tipo_dato>::empty(nodo<tipo_dato>* nodo) const{
    return nodo == nullptr;
}

template<class tipo_dato>
unsigned avl<tipo_dato>::size(void) const{
    return size(raiz_);
}

template<class tipo_dato>
unsigned avl<tipo_dato>::size(nodo<tipo_dato>* nodo) const{
    if(empty(nodo))
        return 0;
    return(1 + size(nodo->izquierda()) + size(nodo->derecha()));
}

template<class tipo_dato>
unsigned avl<tipo_dato>::height(void) const
{
    return height(raiz_);
}

template<class tipo_dato>
unsigned avl<tipo_dato>::height(nodo<tipo_dato>* nodo) const
{
    if(nodo == nullptr)
        return 0;

    return max(height(nodo->izquierda()), height(nodo->derecha()))+1;
}

template<class tipo_dato>
bool avl<tipo_dato>::leaf(nodo<tipo_dato>* nodo){
	return !nodo->derecha() && !nodo->izquierda();
}

template<class tipo_dato>
void avl<tipo_dato>::imprimir_dato(nodo<tipo_dato>* nodo){
    if(nodo == nullptr){
        cout << "[.]";
        return;
    }
	cout << nodo->dato() << " ";
}

template<class tipo_dato>
void avl<tipo_dato>::nivel_orden(void){
	nivel_orden(raiz_);
}

template<class tipo_dato>
void avl<tipo_dato>::nivel_orden(nodo<tipo_dato>* raiz){
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
nodo<tipo_dato>* avl<tipo_dato>::buscar(tipo_dato elemento){
	cp_esta = 0; 
	return buscar(raiz_, elemento);
}

template<class tipo_dato>
nodo<tipo_dato>* avl<tipo_dato>::buscar(nodo<tipo_dato>* nodo, tipo_dato elemento){

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
unsigned avl<tipo_dato>::get_esta(void){
	return cp_esta;
}

template<class tipo_dato>
bool avl<tipo_dato>::balanceado(void){
	return balanceado(raiz_);
}

template<class tipo_dato>
bool avl<tipo_dato>::balanceado(nodo<tipo_dato>* nodo){
	if(nodo == NULL)
		return true;
	int balance = altura(nodo->izquierda()) - altura(nodo->derecha());

	switch(balance){
		case -1:
		case 0:
		case 1:
		return balanceado(nodo->izquierda()) && balanceado(nodo->derecha());
		default: return false;
	}
}

template<class tipo_dato>
void avl<tipo_dato>::rotacion_II(nodo<tipo_dato>*& nodo_pasado){
	
	nodo<tipo_dato>* nodo_copia = nodo_pasado->izquierda();
	nodo_pasado->izquierda() = nodo_copia->derecha();
	nodo_copia->derecha() = nodo_pasado;

	if(nodo_copia->bal() == 1){
		nodo_pasado->bal() = 0;
		nodo_copia->bal() = 0;
	}
	else{
		nodo_pasado->bal() = 1;
		nodo_copia->bal() = -1;
	}
	nodo_pasado = nodo_copia;
}

template<class tipo_dato>
void avl<tipo_dato>::rotacion_DD(nodo<tipo_dato>*& nodo_pasado){
	nodo<tipo_dato>* nodo_copia = nodo_pasado->derecha();
	nodo_pasado->derecha() = nodo_copia->izquierda();
	nodo_copia->izquierda() = nodo_pasado;

	if(nodo_copia->bal() == -1){
		nodo_pasado->bal() = 0;
		nodo_copia->bal() = 0;
	}
	else{
		nodo_pasado->bal() = -1;
		nodo_copia->bal() = 1;
	}
	nodo_pasado = nodo_copia;
}

template<class tipo_dato>
void avl<tipo_dato>::rotacion_ID(nodo<tipo_dato>*& nodo_pasado){
	nodo<tipo_dato>* nodo_copia = nodo_pasado->izquierda();
	nodo<tipo_dato>* nodo_copia_2 = nodo_copia->derecha();
	nodo_pasado->izquierda() = nodo_copia_2->derecha();
	nodo_copia_2->derecha() = nodo_pasado;
	nodo_copia->derecha() = nodo_copia_2->izquierda();
	nodo_copia_2->izquierda() = nodo_copia;

	if(nodo_copia_2->bal() == -1)
		nodo_copia->bal() = 1;
	else
		nodo_copia->bal() = 0;

	if(nodo_copia_2->bal() == 1)
		nodo_pasado->bal() = -1;
	else
		nodo_pasado->bal() = 0;

	nodo_copia_2->bal() = 0;
	nodo_pasado = nodo_copia_2;
}

template<class tipo_dato>
void avl<tipo_dato>::rotacion_DI(nodo<tipo_dato>*& nodo_pasado){
	nodo<tipo_dato>* nodo_copia = nodo_pasado->derecha();
	nodo<tipo_dato>* nodo_copia_2 = nodo_copia->izquierda();
	nodo_pasado->derecha() = nodo_copia_2->izquierda();
	nodo_copia_2->izquierda() = nodo_pasado;
	nodo_copia->izquierda() = nodo_copia_2->derecha();
	nodo_copia_2->derecha() = nodo_copia;

	if(nodo_copia_2->bal() == 1)
		nodo_copia->bal() = -1;
	else
		nodo_copia->bal() = 0;

	if(nodo_copia_2->bal() == -1)
		nodo_pasado->bal() = 1;
	else
		nodo_pasado->bal() = 0;

	nodo_copia_2->bal() = 0;
	nodo_pasado = nodo_copia_2;
}

template <class tipo_dato>
void avl<tipo_dato>::insertar_bal(nodo<tipo_dato>* &nodo_pasado, nodo<tipo_dato>* nuevo, bool& crece){
	if (nodo_pasado == NULL){
		nodo_pasado = nuevo;
		crece = true;
	}
	else if (nuevo->dato() < nodo_pasado->dato()) {
		insertar_bal(nodo_pasado->izquierda(), nuevo, crece);
		if (crece) 
			insertar_rebalancea_izquierda(nodo_pasado, crece);
	}
	else {
		insertar_bal(nodo_pasado->derecha(), nuevo, crece);
		if (crece) 
			insertar_rebalancea_derecha(nodo_pasado, crece);
	}
}

template <class tipo_dato>
void avl<tipo_dato>::insertar_rebalancea_izquierda(nodo<tipo_dato>* &nodo_pasado, bool &crece){
	switch (nodo_pasado->bal()){
		case -1:	
			nodo_pasado->bal() = 0;
			crece = false;
			break;

		case 0:		
			nodo_pasado->bal() = 1;
			break;

		case 1:		
			nodo<tipo_dato>* nodo_copia = nodo_pasado->izquierda();
			if (nodo_copia->bal() == 1)
				rotacion_II(nodo_pasado);
			else 
				rotacion_ID(nodo_pasado);
			crece = false;
			break;
	}
}

template <class tipo_dato>
void avl<tipo_dato>::insertar_rebalancea_derecha(nodo<tipo_dato>* &nodo_pasado, bool &crece){
	switch (nodo_pasado->bal()){
		case 1:		
			nodo_pasado->bal() = 0;
			crece = false;
			break;

		case 0:		
			nodo_pasado->bal() = -1;
			break;

		case -1:	
			nodo<tipo_dato>* nodo_copia = nodo_pasado->derecha();
			if (nodo_copia->bal() == -1)
				rotacion_DD(nodo_pasado);
			else 
				rotacion_DI(nodo_pasado);
			crece = false;
	}
}

template <class tipo_dato>
void avl<tipo_dato>::eliminar_rama(nodo<tipo_dato>* &nodo_pasado, tipo_dato elemento, bool &decrece){
	if (nodo_pasado == NULL) 
		return;
	if (elemento < nodo_pasado->dato()) {
		eliminar_rama(nodo_pasado->izquierda(), elemento, decrece);
		if (decrece)
			eliminar_rebalancea_izquierda(nodo_pasado, decrece);
	}
	else if (elemento > nodo_pasado->dato()) {
		eliminar_rama(nodo_pasado->derecha(), elemento, decrece);
		if (decrece)
			eliminar_rebalancea_derecha(nodo_pasado, decrece);
	}
	else {
		nodo<tipo_dato>* eliminado = nodo_pasado;
		if (nodo_pasado->izquierda() == NULL) {
			nodo_pasado = nodo_pasado->derecha();
			decrece = true;
		}
		else if (nodo_pasado->derecha() == NULL) {
			nodo_pasado = nodo_pasado->izquierda();
			decrece = true;
		}
		else {
			sustituye(eliminado, nodo_pasado->izquierda(), decrece);
			if (decrece)
				eliminar_rebalancea_izquierda(nodo_pasado, decrece);
		}
		delete eliminado;
	}
}

template <class tipo_dato>
void avl<tipo_dato>::eliminar_rebalancea_izquierda(nodo<tipo_dato>* &nodo_pasado, bool &decrece){
	switch (nodo_pasado->bal())	{
		case -1:{	
			nodo<tipo_dato>* nodo_copia = nodo_pasado->derecha();
			if (nodo_copia->bal() > 0)
				rotacion_DI(nodo_pasado);
			else {
				if (nodo_copia->bal() == 0)
					decrece = false;
					rotacion_DD(nodo_pasado);
				}
			break;
		}

		case 0:		
			nodo_pasado->bal() = -1;
			decrece = false;
			break;

		case 1:		
			nodo_pasado->bal() = 0;
			break;
	}
}

template <class tipo_dato>
void avl<tipo_dato>::eliminar_rebalancea_derecha(nodo<tipo_dato>* &nodo_pasado, bool &decrece){
	switch (nodo_pasado->bal())	{
		case 1:{	
			nodo<tipo_dato>* nodo_copia = nodo_pasado->izquierda();
			if (nodo_copia->bal() < 0)
				rotacion_ID(nodo_pasado);
			else {
				if (nodo_copia->bal() == 0)
					decrece = false;
					rotacion_II(nodo_pasado);
				}
			break;
		}

		case 0:		
			nodo_pasado->bal() = 1;
			decrece = false;
			break;

		case -1:	
			nodo_pasado->bal() = 0;
			break;
	}
}

template <class tipo_dato>
void avl<tipo_dato>::sustituye(nodo<tipo_dato>* &eliminado, nodo<tipo_dato>* &sust, bool &decrece){
	if (sust->derecha() != NULL) {
		sustituye(eliminado, sust->derecha(), decrece);
		if (decrece)
			eliminar_rebalancea_derecha(sust, decrece);
	}
	else {
		eliminado->dato() = sust->dato();
		eliminado = sust;
		sust = sust->izquierda();
		decrece = true;
	}
}

template <class tipo_dato>
void avl<tipo_dato>::insertar(tipo_dato elemento)
{
	nodo<tipo_dato>* nuevo = new nodo<tipo_dato>(elemento);
	bool crece = false;
	insertar_bal(raiz_, nuevo, crece);
}

template <class tipo_dato>
void avl<tipo_dato>::eliminar(tipo_dato elemento)
{
	bool decrece = false;
	eliminar_rama(raiz_, elemento, decrece);
}