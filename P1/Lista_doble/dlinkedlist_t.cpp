#include "dlinkedlist_t.hpp"

dlinkedlist_t::dlinkedlist_t (void):
beginning_ (NULL),
end_ (NULL) 
{}

dlinkedlist_t::~dlinkedlist_t(void){
	dll_node_t* aux = beginning_;

	while(aux != NULL){
		beginning_ = beginning_ -> get_next();
		delete aux;
		aux = beginning_;
	}
}

void dlinkedlist_t::insert_beginning(dll_node_t* n){
	n -> set_next (beginning_);

	if (beginning_ != NULL)
		beginning_ -> set_prev (n);
	
	else
		end_ = n;

	beginning_ = n;
	sz_++;
}

dll_node_t* dlinkedlist_t::extract_beginning(void){
	dll_node_t* aux = beginning_;
	beginning_ = beginning_ -> get_next();

	if (beginning_ != NULL)
		beginning_ -> set_prev(NULL);

	else
		end_ = NULL;

	aux-> set_next(NULL);
	sz_--;
	return aux;
}

void dlinkedlist_t::insert_end(dll_node_t* n){
	n -> set_prev (end_);

	if (end_ != NULL)
		end_ -> set_next (n);

	else
		beginning_ = n;

	end_ = n;
	sz_++;
}

dll_node_t* dlinkedlist_t::extract_end(void){
	dll_node_t* aux = end_;
	end_ = end_ -> get_prev ();

	if (end_ != NULL)
		end_ -> set_next (NULL);

	else
		beginning_ = NULL;

	aux -> set_prev(NULL);
	sz_--;
	return aux;
}

bool dlinkedlist_t::empty(void) const{
	return (beginning_==NULL);
}

unsigned int dlinkedlist_t::size(void) const{
	return sz_;
}

ostream& dlinkedlist_t::write(ostream& os) const{
	dll_node_t* aux = beginning_;
	
	while (aux != NULL){
	os << aux;
	aux = aux -> get_next();
	}

	return os;
}
