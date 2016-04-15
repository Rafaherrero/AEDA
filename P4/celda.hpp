#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <vector>

#pragma once

using namespace std;

template<class tipo_clave>
class celda{
private:
    vector<tipo_clave> *celda_;
    unsigned sz_;
public:
    celda(void);
    celda(unsigned size);
    ~celda(void);

    bool busqueda(tipo_clave* cv);
    bool insertar(tipo_clave* cv);
    tipo_clave get_valor(unsigned pos);
};

template<class tipo_clave>
celda<tipo_clave>::celda(void):
celda_(0),
sz_(0)
{}

template<class tipo_clave>
celda<tipo_clave>::celda(unsigned size):
sz_(size)
{
    celda_ = new vector<tipo_clave>(sz_);
}

template<class tipo_clave>
celda<tipo_clave>::~celda(void)
{
}

template<class tipo_clave>
bool celda<tipo_clave>::busqueda(tipo_clave* cv){
    for(unsigned i = 0; i < sz_; i++)
        if(celda_[i] == cv)
            return true;
    return false;
}

template<class tipo_clave>
bool celda<tipo_clave>::insertar(tipo_clave* cv){
    for(unsigned i = 0; i < sz_; i++){
        if(celda_[i] == nullptr){
            celda_[i] = cv;
            return true;
        }
    }
    return false;
}

template<class tipo_clave>
tipo_clave celda<tipo_clave>::get_valor(unsigned pos){
    return celda_[pos];
}