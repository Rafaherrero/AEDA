#include <cstddef>
#include "stack_t.hpp"

using namespace std;

stack_t::stack_t(void):
base_(NULL),
top_(0),
sz_(0)
{}

stack_t::stack_t(unsigned int size):
base_(NULL),
top_(0),
sz_(size)
{
	build(size);
}

stack_t::~stack_t(void){
	destroy();
}

void stack_t::build (unsigned int size){
	base_= new TDATO[size];
	sz_ = size;
}

void stack_t::destroy (void){
	if (base_ != NULL){
		delete[] base_;
		base_ = NULL;
		top_ = 0;
		sz_ = 0;
	}
}

void stack_t::push (TDATO dato){
	if (!full()){
		base_[top_] = dato;
		top_++;
	}
	else{
		cerr << "La pila esta llena" << endl;
	}
}

TDATO stack_t::pop (void){
	if (!empty()){
		top_--;
		return base_[top_];
	}
	else{
		cerr << "La pila esta vacia" << endl;
	}

}

TDATO& stack_t::top (void) const{
	if (!empty())
		return base_[top_-1];
	else
		cerr << "La pila esta vacia" << endl;
}

unsigned int stack_t::size (void) const{
	return sz_;
}

bool stack_t::empty (void) const{
	return (top_==0);
}

bool stack_t::full (void) const{
	return (top_==sz_);
}

void stack_t::resize (unsigned int tamano){
	if (tamano>0){
		destroy();
		build (tamano);
	}
	else
		cerr << "Error en el tamano" << endl;
}

void stack_t::resize_copia (unsigned int tamano){
	if (tamano>0&&!empty()){
		stack_t copia(size());
		for (int i=0; i<size();i++){
			copia.push(pop());
		}
		resize(tamano);
		if (copia.size()<size()){
			for (int i=0; i<copia.size();i++)
				push(copia.pop());
			copia.destroy();
		}
		else{
			for (int i=0; i<size(); i++)
				push(copia.pop());
			copia.destroy();	
		}
	}
	else
		cerr << "Error en el tamano" << endl;
}
