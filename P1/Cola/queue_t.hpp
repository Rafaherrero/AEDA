#include "../common.hpp"

class queue_t
{
private:
	TDATO* base_;
	unsigned int rear_;
	unsigned int sz_;
public:
	queue_t(void);
	~queue_t(void);
	queue_t(unsigned int size);
	void build(void);
	void build (unsigned int size);
	void destroy(void);
	void push(TDATO dato);
	TDATO pop(void);
	TDATO& back(void) const;
	TDATO& front(void) const;
	unsigned int size(void) const;
	bool empty(void) const;
	bool full(void) const;
	void resize (unsigned int tamano);
	void resize_copia (unsigned int tamano);
};