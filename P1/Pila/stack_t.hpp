#include "../common.hpp"

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
