#pragma once
#include <iostream>
#include <cstring>
#include "../numero_t.hpp"
#include "../Racional/racional.hpp"
#include "../Complejo/complejo.hpp"
#include "../Entero/entero.hpp"
#include "../Real/real.hpp"
#include "../excepciones.hpp"

#define VEC_MAX_SIZE 32767

template<class T>
class vector_t
{
private:
	T *v_;
	unsigned int sz_;
	unsigned int msz_;
	unsigned int buffer_;
	unsigned int first_;
	unsigned int last_;
public:

	vector_t(void);
	vector_t(unsigned int);
	~vector_t(void);

	inline unsigned int size(void) const;
	void resize(unsigned int);
	inline unsigned int capacity(void) const;
	bool empty(void) const;
	
	T& operator[](unsigned int) const;
	T& at(unsigned int) const;
	T& front(void);
	T& back(void);
	
	void push_back(const T&);
	void pop_back(void);

};

template<class T>
vector_t<T>::vector_t(void):
	v_(nullptr),
	sz_(0),
	msz_(10),
	buffer_(10),
	first_(0),
	last_(0)
{}

template<class T>
vector_t<T>::vector_t(unsigned int sz):
	v_(nullptr),
	sz_(sz),
	msz_(sz + 10),
	buffer_(10),
	first_(0),
	last_(sz_)
{
	if(msz_ > VEC_MAX_SIZE)
		throw exception::length_error("Exceeded max vector_t size 'VEC_MAX_SIZE'");
	try{
		v_ = new T[msz_];
	}catch(...){
		throw exception::mem_error("Memory error (full memory?)");
	}
}


template<class T>
vector_t<T>::~vector_t(void)
{
	if(v_ != nullptr)
		delete[] v_;
}

template<class T>
unsigned int vector_t<T>::size(void) const
{
	return sz_;
}

template<class T>
void vector_t<T>::resize(unsigned int new_sz)
{
	sz_ = new_sz;
	if(new_sz > msz_){

		if(sz_ > VEC_MAX_SIZE)
			throw exception::length_error("Exceeded max vector_t size 'VEC_MAX_SIZE'");

		if((sz_ + buffer_) > (VEC_MAX_SIZE))
			buffer_ = 0; //Pasamos de usar el buffer

		msz_ = sz_ + buffer_;

		T* tmp_ptr = nullptr;
		try{
			tmp_ptr = new T[msz_];
		}catch(...){
			throw exception::mem_error("Memory error (full memory?)");
		}
		memcpy(tmp_ptr, v_, sz_*sizeof(T));

		delete[] v_;
		v_ = tmp_ptr;
	}
	last_ = sz_+first_;
}

template<class T>
inline unsigned int vector_t<T>::capacity(void) const
{
	return msz_;
}

template<class T>
bool vector_t<T>::empty(void) const
{
	return (sz_ == 0);
}

template<class T>
T& vector_t<T>::operator[](unsigned int position) const
{	
	return at(position);
}

template<class T>
T& vector_t<T>::at(unsigned int position) const
{
	if((position < first_) || (position >= last_) || empty())
		throw exception::out_of_range();
	else
		return v_[position-first_];
}

template<class T>
T& vector_t<T>::front(void)
{
	return at(first_);
}

template<class T>
T& vector_t<T>::back(void)
{
	return at(last_-1);
}

template<class T>
void vector_t<T>::push_back(const T& val)
{
	resize(sz_+1);
	back() = val;
}

template<class T>
void vector_t<T>::pop_back(void)
{
	resize(sz_-1);
}