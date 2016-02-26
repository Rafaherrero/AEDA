#include "../common.hpp"
#include "dll_node_t.hpp"

using namespace std;

class dlinkedlist_t {

private:
	dll_node_t* beginning_;
	dll_node_t* end_;
	unsigned int sz_;

public:
	dlinkedlist_t(void);
	virtual ~dlinkedlist_t(void);

	void insert_beginning(dll_node_t* n);
	dll_node_t* extract_beginning(void);

	void insert_end(dll_node_t* n);
	dll_node_t* extract_end(void);

	bool empty(void) const;
	ostream& write(ostream& os) const;

	unsigned int size(void) const;

	void insert_pos(dll_node_t* n, unsigned int pos);

};