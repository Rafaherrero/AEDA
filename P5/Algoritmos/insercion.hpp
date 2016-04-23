#include "../common.hpp"
#pragma once

using namespace std;

template<class tipo_vector>
vector<tipo_vector> insercion(vector<tipo_vector> v){
	
	tipo_vector temp;
	int i,j;

	for (i=1; i<v.size(); i++){
		
		temp = v[i];
		j = i - 1;

		while ((v[j] > temp) && (j >= 0)){
       		v[j+1] = v[j];
    	    j--;
    	}
    	v[j+1] = temp;
	}
	return v;
}