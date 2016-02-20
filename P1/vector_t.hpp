#include "common.hpp"

class vector_t
{
	private:
		TDATO* base_;	/* Puntero a clase */
		int sz_;	//tamaño

	public:
		vector_t(void);	//constructor por defecto
		vector_t(int sz);	//constructor en el que pasaremos el tamaño
		virtual ~vector_t(void);	//destructor
		void resize(int sz);	//redimensionar vector
		TDATO& operator[] (int pos);	//
		TDATO& operator[] (int pos) const; //acceder a un elemento constante
		int get_size(void); // conocer el tamaño del vector

	private:
		void build(int sz);	//
		void clean(void);	//
};
