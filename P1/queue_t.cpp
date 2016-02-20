#include "queue_t.hpp"

queue_t::queue_t(void):
base_(nullptr),
front(-1),
rear(0),
sz_(0)
{}

queue_t::queue_t(unsigned int size):
base_(nullptr),
front(-1),
rear(0),
sz_(size)
{
	build();
}

queue_t::~queue_t(void){
	destroy();
}

queue_t::build (void){
	base_= new TDATO[sz_];
}