#pragma once
#include <iostream>
#include <cstring>
#include "../numero_t.hpp"
#include "../Racional/racional.hpp"
#include "../Complejo/complejo.hpp"
#include "../Entero/entero.hpp"
#include "../Real/real.hpp"
#include "../excepciones.hpp"

#include "node_t.hpp"


template<class T>
class list_t
{
private:
    node_t<T>* start_; //puntero al primer elemento de la lista enlazada
    node_t<T>* end_; //puntero al último elemento de la lista enlazada
private:
    void first(node_t<T>*); //se llama para la primera incersión
public:
    list_t(void);
    ~list_t(void);
    
    inline bool empty(void) const;
    
    void push_back(node_t<T>*); //mete un nodo al final de la lista
    void push_front(node_t<T>*); //mete un nodo al principio de la lista
    
    node_t<T>* extract_back(void); //extrae el último nodo
    node_t<T>* extract_front(void); //extrae el primer nodo
};

template<class T>
list_t<T>::list_t(void):
start_(nullptr),
end_(nullptr)
{}

template<class T>
list_t<T>::~list_t(void)
{
    node_t<T>* tmp_ptr = start_;
    while(start_ != nullptr)
    {
        start_ = start_ -> next();
        delete tmp_ptr;
        tmp_ptr = start_;
    }
}

template<class T>
void list_t<T>::first(node_t<T>* node_t)
{
    node_t->next() = nullptr;
    start_ = node_t;
    end_ = node_t;
}

template<class T>
bool list_t<T>::empty(void) const
{
    return (start_ == nullptr);
}

template<class T>
void list_t<T>::push_back(node_t<T>* node_t)
{
    if(empty()) first(node_t);
    else{
        node_t->next() = nullptr;
        end_->next() = node_t;
        end_ = node_t;
    }
}

template<class T>
void list_t<T>::push_front(node_t<T>* node_t)
{
    if(empty()) first(node_t);
    else{
        node_t->next() = start_;
        start_ = node_t;
    }
}

template<class T>
node_t<T>* list_t<T>::extract_back(void)
{
    if(empty())
        throw exception::length_error("List was empty");
    node_t<T>* tmp_ptr = start_;
    if(start_ == end_){
        start_ = nullptr;
        end_ = nullptr;
    }
    else{
        while(tmp_ptr->next() != end_) //al final, tmp_ptr apunta al penúltimo nodo
            tmp_ptr = tmp_ptr->next();
        end_ = tmp_ptr;
        tmp_ptr = tmp_ptr->next();
        end_->next() = nullptr;
    }
    return tmp_ptr;
}

template<class T>
node_t<T>* list_t<T>::extract_front(void)
{
    if(empty())
        throw exception::length_error("List was empty");
    node_t<T>* tmp_ptr = start_;
    if(start_ == end_){
        start_ = nullptr;
        end_ = nullptr;
    }
    else{
        start_ = start_->next();
        tmp_ptr->next() = nullptr;
    }
    return tmp_ptr;
}
