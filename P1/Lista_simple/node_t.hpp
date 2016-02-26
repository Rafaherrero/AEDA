#include "../common.hpp"

class node_t
{
	private:
		TDATO dato_;
		node_t* next_;

	public:
		node_t(void);
		node_t(TDATO dato);
		~node_t(void);
		node_t* get_next(void);
		TDATO get_dato(void);
		void set_next(node_t* next);
		void set_dato(TDATO dato);
};
