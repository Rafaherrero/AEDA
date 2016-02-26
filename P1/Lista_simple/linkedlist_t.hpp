#include "../common.hpp"
#include "node_t.hpp"

class linkedlist_t	{

private:

	node_t* beginning_;
	unsigned int sz_;

public:

	linkedlist_t(void);
	~linkedlist_t(void);

	void insertar_inicio (node_t* n);
	node_t* extraer_inicio();
	void insertar_after (node_t* prev, node_t* n);
	node_t* extraer_after (node_t* prev);
	unsigned int size (void);
};
