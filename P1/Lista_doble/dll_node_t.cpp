#include "dll_node_t.hpp"

dll_node_t::dll_node_t(void):
	dato_(),
	next_(NULL)
	{}

dll_node_t::dll_node_t(TDATO dato):
	dato_(dato),
	next_(NULL)
	{}

dll_node_t::~dll_node_t(void)
{}

dll_node_t* dll_node_t::get_next()
{
	return next_;
}

TDATO dll_node_t::get_dato()
{
	return dato_;
}

void dll_node_t::set_next(dll_node_t* next)
{
	next_ = next;
}

void dll_node_t::set_dato(TDATO dato)
{
	dato_ = dato;
}
