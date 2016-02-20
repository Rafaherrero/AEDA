#include "common.hpp"

class vector_t
{
	private:
		TDATO* base_;
		int sz_;

	public:
		vector_t(void);
		vector_t(int sz);
		virtual ~vector_t(void);
		void resize(int sz);
		TDATO& operator[] (int pos);
		TDATO& operator[] (int pos) const; 
		int get_size(void); 

	private:
		void build(int sz);
		void clean(void);
};
