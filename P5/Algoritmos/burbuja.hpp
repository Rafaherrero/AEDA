#include "../common.hpp"
#pragma once

using namespace std;

template<class tipo_vector>
vector<tipo_vector> burbuja(vector<tipo_vector> v){

	tipo_vector tp;
	int i,j;

	for (i=1; i<v.size(); i++){
   		for (j=0 ; j<v.size() - 1; j++){
    		if (v[j] > v[j+1]){     
				tp = v[j];   
    			v[j] = v[j+1];   
    			v[j+1] = tp;
    		}
    	}
    }
    return v;
}