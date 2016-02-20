#include "common.hpp"

class queue_t
{
private:
	TDATO* base_;
	int front;
	unsigned int rear;
	unsigned int sz_;
public:
	queue_t(void);
	~queue_t(void);
	void build(void);
	void destroy(void);
	void push(TDATO it);
	TDATO pop(void);
	TDATO& front(void) const;
	TDATO& rear(void) const;
	unsigned int size(void) const;
};