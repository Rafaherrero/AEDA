#include "../common.hpp"
#pragma once

using namespace std;

template<class tipo_vector>
unsigned long int burbuja(vector<tipo_vector> &v, unsigned modo){

	tipo_vector tp;
	int i,j;
    unsigned long int cp = 0;

	for (i=1; i<v.size(); i++){
   		for (j=0 ; j<v.size() - 1; j++){
            cp++;
    		if (v[j] > v[j+1]){     
				tp = v[j];   
    			v[j] = v[j+1];   
    			v[j+1] = tp;
    		}
    	}
    }
    return cp;
}