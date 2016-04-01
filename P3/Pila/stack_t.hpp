#pragma once
#include <iostream>
#include <cstring>
#include "../numero_t.hpp"
#include "../Racional/racional.hpp"
#include "../Complejo/complejo.hpp"
#include "../Entero/entero.hpp"
#include "../Real/real.hpp"
#include "../excepciones.hpp"

using namespace std;

#define STK_EMPTY_stack_t 4294967295
#define STK_DEFAULT_BUFFER_SIZE 10
#define STK_MAX_SIZE 4294967294

template<class T>
class stack_t
{
	private:
	T *s_;
	unsigned int sz_;
	unsigned int msz_;
	unsigned int top_;
	unsigned int buffer_;
	public:
	
	stack_t(void);
	stack_t(unsigned int);
	stack_t(const stack_t&);
	~stack_t(void);
	
	inline bool empty(void) const;
	unsigned int size(void) const;
	void resize(unsigned int);
	
	T& top(void);
	T top(void) const;
	
	void push(const T&);
	void pop(void);
	
};

template<class T>
stack_t<T>::stack_t(void):
s_(nullptr),
sz_(0),
msz_(sz_+buffer_),
top_(STK_EMPTY_stack_t),
buffer_(STK_DEFAULT_BUFFER_SIZE)
{
	resize(0);
}

template<class T>
stack_t<T>::stack_t(unsigned int sz):
s_(nullptr),
sz_(0),
msz_(0),
top_(STK_EMPTY_stack_t),
buffer_(STK_DEFAULT_BUFFER_SIZE)
{
	resize(sz);
}

template<class T>
stack_t<T>::stack_t(const stack_t& s)
{
	*this = s;
}

template<class T>
stack_t<T>::~stack_t(void)
{
	if(s_ != nullptr)
		delete[] s_;
}

template<class T>
bool stack_t<T>::empty(void) const
{
	return (top_ == STK_EMPTY_stack_t);
}

template<class T>
unsigned int stack_t<T>::size(void) const
{
	return sz_;
}

template<class T>
void stack_t<T>::resize(unsigned int new_sz)
{
	if((new_sz > msz_)  || (s_ == nullptr)){
		if(new_sz > STK_MAX_SIZE)
			throw exception::length_error("Exceeded max vector size 'STK_MAX_SIZE'");
		sz_ = new_sz;
		
		if((sz_+buffer_) > STK_MAX_SIZE)
			buffer_ = sz_ - STK_MAX_SIZE;
		
		msz_ = sz_ + buffer_;
		
		T *tmp_ptr = nullptr;
		
		try{
			tmp_ptr = new T[msz_];
		}catch(...){
			throw exception::mem_error("Memory error (full memory?)");
		}
		
		if(s_ != nullptr){
			memcpy(tmp_ptr, s_, sz_*sizeof(T));
			delete[] s_;
		}
		s_ = tmp_ptr;
	}
	else
		sz_ = new_sz;
}

template<class T>
T& stack_t<T>::top(void)
{
	return s_[top_];
}

template<class T>
T stack_t<T>::top(void) const
{
	return s_[top_];
}

template<class T>
void stack_t<T>::push(const T& val)
{
	top_++;
	if(top_ > STK_MAX_SIZE)
		throw exception::length_error("stack_t overflow!");
	
	if(top_ >= sz_)
		resize(sz_+1);
	
	s_[top_] = val;
}

template<class T>
void stack_t<T>::pop(void)
{
	if(empty())
		throw exception::length_error("stack_t underflow!");
	
	top_--;
}

