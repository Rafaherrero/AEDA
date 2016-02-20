#include "vector_t.hpp"

using namespace std;

void vector_t::build(int sz)
{
	if(base_ == NULL)
	{
		base_ = new TDATO[sz];
		sz_ = sz;
	}
	else
	{
		cerr << "ERROR" << endl;
	}
}

void vector_t::clean (void)
{
	if(base_ != NULL)
	{
		delete[] base_;
		base_ = NULL;
		sz_ = 0;
	}
}

vector_t::vector_t(void):
	base_(NULL),
	sz_(0)
	{}

vector_t::vector_t(int sz):
	base_(NULL),
	sz_(0)
	{
		build(sz);
	}

vector_t::~vector_t(void)
{
	clean();
}

void vector_t::resize(int sz)
{
	clean();

	if(sz > 0)
	{
		build(sz);
	}
}

TDATO& vector_t::operator[] (int pos)
{
	return base_[pos];
}

TDATO& vector_t::operator[] (int pos) const
{
	return base_[pos];
}

int vector_t::get_size(void)
{
	return sz_;
}