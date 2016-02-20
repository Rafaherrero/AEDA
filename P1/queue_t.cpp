#include "queue_t.hpp"

queue_t::queue_t(void):
base_(nullptr),
rear(0),
sz_(0)
{}

queue_t::queue_t(unsigned int size):
base_(nullptr),
rear(0),
sz_(size)
{
	build();
}

queue_t::~queue_t(void){
	destroy();
}

void queue_t::build (void){
	base_= new TDATO[sz_];
}

void queue_t::destroy (void){
	if (base_ != nullptr){
		delete[] base_;
		base_ = nullptr;
		rear = 0;
		front = -1;
		sz_ = 0;
	}
}

void queue_t::push (TDATO dato){
	if (!full()){
		rear++;
		base_[rear] = dato;
	}
}