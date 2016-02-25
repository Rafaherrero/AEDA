#include "../common.hpp"
#include "dll_node_t.hpp"

using namespace std;

class dlinkedlist_t {

private:
	dll_node_t* beginning_;
	dll_node_t* end_;

public:
	dll_t(void);
	virtual ~dll_t(void);

	void insert_beginning(dll_node_t* n);
	dll_node_t* extract_beginning(void);

	void insert_end(dll_node_t* n);
	dll_node_t* extract_end(void);

	bool empty(void) const;
	ostream& write(ostream& os) const;

};