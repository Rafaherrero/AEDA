#include "linkedlist_t.hpp"

linkedlist_t::linkedlist_t(void):
	beginning_(NULL),
	sz_(0)
{}

linkedlist_t::~linkedlist_t(void){
	node_t* aux = NULL;

	while (beginning_ != NULL){
		aux = beginning_;
		beginning_ = beginning_->get_next();
		delete aux;
	}
}

void linkedlist_t::insertar_inicio (node_t* n){
	n->set_next(beginning_);
	beginning_ = n;
	sz_++;
}

node_t* linkedlist_t::extraer_inicio(){
	node_t* aux = beginning_;
	beginning_ = beginning_ -> get_next();
	aux -> set_next (NULL);
	return aux;
	sz_--;
}

void linkedlist_t::insertar_after (node_t* prev, node_t* n){
	n-> set_next (prev -> get_next());
	prev -> set_next (n);
	sz_++;
}

node_t* linkedlist_t::extraer_after (node_t* prev){
	node_t* aux = prev -> get_next();
	prev -> set_next(aux -> get_next());
	aux -> set_next(NULL);
	sz_--;
	return aux;
}

unsigned int linkedlist_t::size(void){
	return sz_;
}