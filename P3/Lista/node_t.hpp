#include <iostream>

template<class T>
class node_t{
private:
    node_t *next_;
    T data_;
public:
    node_t(void);
    node_t(const T& data);
    ~node_t(void);
    
    node_t*& next(void);
    
    T& data(void);
    
};

template<class T>
node_t<T>::node_t(void):
next_(nullptr),
data_()
{}

template<class T>
node_t<T>::node_t(const T& data):
next_(nullptr),
data_(data)
{}

template<class T>
node_t<T>::~node_t(void)
{}

template<class T>
node_t<T>*& node_t<T>::next(void)
{
    return next_;
}

template<class T>
T& node_t<T>::data(void)
{
    return data_;
}