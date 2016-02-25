#include "node_t.hpp"

node_t::node_t(void):
	dato_(),
	next_(NULL)
	{}

node_t::node_t(TDATO dato):
	dato_(dato),
	next_(NULL)
	{}

node_t::~node_t(void)
{}

node_t* node_t::get_next()
{
	return next_;
}

TDATO node_t::get_dato()
{
	return dato_;
}

void node_t::set_next(node_t* next)
{
	next_ = next;
}

void node_t::set_dato(TDATO dato)
{
	dato_ = dato;
}
