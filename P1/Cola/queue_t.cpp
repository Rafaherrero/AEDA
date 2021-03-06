#include <cstddef>
#include "queue_t.hpp"

using namespace std;

queue_t::queue_t(void):
base_(NULL),
rear_(0),
sz_(0)
{}

queue_t::queue_t(unsigned int size):
base_(NULL),
rear_(0),
sz_(size)
{
	build(size);
}

queue_t::~queue_t(void){
	destroy();
}

void queue_t::build (unsigned int size){
	base_= new TDATO[size];
	sz_ = size;
}

void queue_t::destroy (void){
	if (base_ != NULL){
		delete[] base_;
		base_ = NULL;
		rear_ = 0;
		sz_ = 0;
	}
}

void queue_t::push (TDATO dato){
	if (!full()){
		base_[rear_] = dato;
		rear_++;
	}
	else{
		sz_++;
		resize_copia(sz_);
		base_[rear_] = dato;
		rear_++;
	}
}

TDATO queue_t::pop (void){
	if (!empty()){
		TDATO dato_pop = base_[0];
		for(int i = 1; i <= rear_; i++)
			base_[i-1] = base_[i];
		rear_--;
		return dato_pop;
	}
	else{
		cerr << "La cola esta vacia" << endl;
	}

}

TDATO& queue_t::back (void) const{
	if (!empty())
		return base_[rear_-1];
		
	else
		cerr << "La cola esta vacia" << endl;
}

TDATO& queue_t::front (void) const{
	if (!empty())
		return base_[0];
	else
		cerr << "La cola esta vacia" << endl;
}

unsigned int queue_t::size (void) const{
	return sz_;
}

bool queue_t::empty (void) const{
	return (rear_==0);
}

bool queue_t::full (void) const{
	return (rear_==sz_);
}

void queue_t::resize (unsigned int tamano){
	if (tamano>0){
		destroy();
		build (tamano);
	}
	else
		cerr << "Error en el tamano" << endl;
}

void queue_t::resize_copia (unsigned int tamano){
	if (tamano>0&&!empty()){
		queue_t copia(size());
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
