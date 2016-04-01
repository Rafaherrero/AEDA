#include <iostream>
#include <cstring>
#include "../numero_t.hpp"
#include "../Racional/racional.hpp"
#include "../Complejo/complejo.hpp"
#include "../Entero/entero.hpp"
#include "../Real/real.hpp"
#include "../excepciones.hpp"

#define QUE_EMPTY_queue_t 4294967295 //Realmente, es un -1, si le hacemos ++ da 0;
#define QUE_MAX_SIZE 4294967294

using namespace std;

template<class T>
class queue_t{
private:
	T* q_;
	unsigned int sz_;
	unsigned int msz_;
	unsigned int rear_;
	unsigned int buffer_;
public:
	
	queue_t(void);
	queue_t(unsigned int);
	~queue_t(void);
	
	inline bool empty(void) const;
	void resize(unsigned int size);
	unsigned int size(void) const;
	
	T& front(void);
	T& rear(void);
	
	void push(const T& val);
	void pop(void);
};

template<class T>
queue_t<T>::queue_t(void):
q_(nullptr),
sz_(0),
msz_(sz_+buffer_),
rear_(QUE_EMPTY_queue_t),
buffer_(10)
{
	resize(0);
}

template<class T>
queue_t<T>::queue_t(unsigned int sz):
q_(nullptr),
sz_(0),
msz_(sz_+buffer_),
rear_(QUE_EMPTY_queue_t),
buffer_(10)
{
	resize(sz);
}

template<class T>
queue_t<T>::~queue_t(void)
{
	if(q_ != nullptr)
		delete[] q_;
}

template<class T>
bool queue_t<T>::empty(void) const
{
	return (rear_ == QUE_EMPTY_queue_t);
}

template<class T>
void queue_t<T>::resize(unsigned int new_sz)
{
	if((new_sz > msz_)  || (q_ == nullptr)){
		if(new_sz > QUE_MAX_SIZE)
			throw exception::length_error("Exceeded max vector size 'QUE_MAX_SIZE'");
		
		sz_ = new_sz;
		
		if((sz_+buffer_) > QUE_MAX_SIZE)
			buffer_ = QUE_MAX_SIZE - sz_;
		
		msz_ = sz_ + buffer_;
		
		T *tmp_ptr = nullptr;
		
		try{
			tmp_ptr = new T[msz_];
		}
		catch(...){
			throw exception::mem_error("Memory error (full memory?)");
		}
		
		if(q_ != nullptr){
			memcpy(tmp_ptr, q_, sz_*sizeof(T));
			delete[] q_;
		}
		q_ = tmp_ptr;
	}
	else
		sz_ = new_sz;
}

template<class T>
unsigned int queue_t<T>::size(void) const
{
	return msz_;
}

template<class T>
T& queue_t<T>::front(void)
{
	if(empty())
		throw exception::length_error("Empty queue_t!");
	return q_[0];
}

template<class T>
T& queue_t<T>::rear(void)
{
	if(empty())
		throw exception::length_error("Empty queue_t!");
	return q_[rear_];
}

template<class T>
void queue_t<T>::push(const T& val)
{
	rear_++;
	if(rear_ >= sz_)
		resize(sz_+1);
	q_[rear_] = val;
	
}

template<class T>
void queue_t<T>::pop(void)
{
	if(empty())
		throw exception::length_error("Empty queue_t!");
	rear_--;
}
