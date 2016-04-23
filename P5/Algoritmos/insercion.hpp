#include "../common.hpp"
#pragma once

using namespace std;

template<class tipo_vector>
void insercion(vector<tipo_vector> v){
	for (int i=0; i<v.size(); i++)
		cout << "Estoy imprimiendo el vector: " << v[i].get_dni() << endl;
}