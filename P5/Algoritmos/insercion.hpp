#include "../common.hpp"
#pragma once

using namespace std;

template<class tipo_vector>
vector<tipo_vector> insercion(vector<tipo_vector> v, unsigned modo){
	
	tipo_vector tp;
	int i,j;

	if (modo==0){
		cout << "Vector antes de ejecutar insercion: " << endl;
		for (int i=0; i < v.size(); i++)
			cout << i+1 << ". " << v[i] << endl;
	}

	for (i=1; i<v.size(); i++){
		
		tp = v[i];
		j = i - 1;

		while ((v[j] > tp) && (j >= 0)){
       		v[j+1] = v[j];
    	    j--;
    	}
    	v[j+1] = tp;
	}
	return v;
}