using namespace std;

template<class tipo_vector>
unsigned long int mergesort(vector<tipo_vector> &v, unsigned modo){
	unsigned long int cp=0;
	Msort(v,0,v.size()-1,cp, modo);
	return cp;
}

template<class tipo_vector>
void Msort(vector<tipo_vector> &v, int inicio, int fin, unsigned long int &cp, unsigned modo){
	int cen;
	cp++; 

	if (inicio < fin){ 

		if(modo==0)
			cout << "Como inicio: " << inicio << " es más pequeño que fin: " << final << ", dividimos la secuencia por la mitad." << endl;

		cen = (inicio + fin)/2;
		Msort (v, inicio, cen, cp, modo);
		Msort (v, cen+1, fin, cp, modo);
		Mezcla (v, inicio, cen, fin, cp, modo);
	}
}

template<class tipo_vector>
void Mezcla(vector<tipo_vector> &v, int inicio, int cen, int fin, unsigned long int &cp, unsigned modo){

	int i = inicio, j = cen+1, k = inicio;
	auto tp = v;
	cp++;
	while ((i <= cen) && (j <= fin)){
		cp++; 
		if (v[i] < v[j]){
		 	tp[k] = v[i];
			i++;
			}
		else{ 
			tp[k] = v[j];
			j++;
			}
		k++;
	}
	cp++;
	if(i > cen){
		cp++;
		while (j <= fin){ 
			tp[k] = v[j];
			j++; 
			k++;
		}
	}
	else{
		cp++;
		while (i <= cen){ 
			tp[k] = v[i];
			i++; 
			k++;
		}
	}

	for (int k = inicio; k <= fin; k++)
		v[k] = tp[k] ;
}