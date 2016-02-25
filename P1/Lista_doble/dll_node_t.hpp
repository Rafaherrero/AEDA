class dll_node_t
{
	private:
		TDATO dato_;
		dll_node_t* next_;
		dll_node_t* prev_;

	public:
		dll_node_t(void);
		dll_node_t(TDATO dato);
		~dll_node_t(void);
		dll_node_t* get_next(void);
		TDATO get_dato(void);
		void set_next(dll_node_t* next);
		void set_dato(TDATO dato);
		dll_node_t* get_prev(void);
		void set_prev(dll_node_t* prev);
};
