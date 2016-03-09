#include <cstddef>
#include <iostream>

using namespace std;

template<class TDATO>
class stack_t
{
private:
	TDATO* base_;
	unsigned int sz_;
	unsigned int top_;

public:
	stack_t(void);
	~stack_t(void);
	stack_t(unsigned int size);
	bool empty(void) const;
	bool full(void) const;
	unsigned int size(void) const;
	void resize (unsigned int tamano);
	void resize_copia (unsigned int tamano);
	void push(TDATO dato);
	TDATO pop(void);
	void build(void);
	void build (unsigned int size);
	void destroy(void);
	TDATO& top(void) const;
};

template<class TDATO>
stack_t<TDATO>::stack_t(void):
base_(NULL),
top_(0),
sz_(0)
{}

template<class TDATO>
stack_t<TDATO>::stack_t(unsigned int size):
base_(NULL),
top_(0),
sz_(size)
{
	build(size);
}

template<class TDATO>
stack_t<TDATO>::~stack_t(void){
	destroy();
}

template<class TDATO>
void stack_t<TDATO>::build (unsigned int size){
	base_= new TDATO[size];
	sz_ = size;
}

template<class TDATO>
void stack_t<TDATO>::destroy (void){
	if (base_ != NULL){
		delete[] base_;
		base_ = NULL;
		top_ = 0;
		sz_ = 0;
	}
}

template<class TDATO>
void stack_t<TDATO>::push (TDATO dato){
	if (!full()){
		base_[top_] = dato;
		top_++;
	}
	else{
		sz_++;
		resize_copia(sz_);
		base_[top_] = dato;
		top_++;
	}
}

template<class TDATO>
TDATO stack_t<TDATO>::pop (void){
	if (!empty()){
		top_--;
		return base_[top_];
	}
	else{
		cerr << "La pila esta vacia" << endl;
	}

}

template<class TDATO>
TDATO& stack_t<TDATO>::top (void) const{
	if (!empty())
		return base_[top_-1];
	else
		cerr << "La pila esta vacia" << endl;
}

template<class TDATO>
unsigned int stack_t<TDATO>::size (void) const{
	return sz_;
}

template<class TDATO>
bool stack_t<TDATO>::empty (void) const{
	return (top_==0);
}

template<class TDATO>
bool stack_t<TDATO>::full (void) const{
	return (top_==sz_);
}

template<class TDATO>
void stack_t<TDATO>::resize (unsigned int tamano){
	if (tamano>0){
		destroy();
		build (tamano);
	}
	else
		cerr << "Error en el tamano" << endl;
}

template<class TDATO>
void stack_t<TDATO>::resize_copia (unsigned int tamano){
	if (tamano>0&&!empty()){
		stack_t copia(size());
		for (int i=0; i<size()-1;i++){
			copia.push(pop());
		}
		resize(tamano);
		if (copia.size()<size()){
			for (int i=0; i<copia.size()-1;i++)
				push(copia.pop());
			copia.destroy();
		}
		else{
			for (int i=0; i<size()-1; i++)
				push(copia.pop());
			copia.destroy();	
		}
	}
	else
		cerr << "Error en el tamano" << endl;
}
