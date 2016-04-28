using namespace std;

template<class tipo_vector>
void Mezcla(vector<tipo_vector> &v, int inicio, int cen, int fin, unsigned long int &cp, unsigned modo){

	int i = inicio, j = cen+1, k = inicio;
	auto tp = v;

	while ((i <= cen) && (j <= fin)){
		cp++; 
		if (v[i] < v[j]){

			if(modo==0)
				cout << "Como el valor de la posicion " << i+1 << ": " << v[i] << " es mas pequeño que el de la posicion " << j+1 << ": " << v[j] << ", no intercambiamos." << endl;

		 	tp[k] = v[i];
			i++;
			}
		else{ 

			if(modo==0)
				cout << "Como el valor de la posicion " << i+1 << ": " << v[i] << " es igual o mas grande que el de la posicion " << j+1 << ": " << v[j] << ", intercambiamos." << endl;

			tp[k] = v[j];
			j++;
			}
		k++;
	}

	if(i > cen){

		while (j <= fin){ 
			tp[k] = v[j];
			j++; 
			k++;
		}
	}
	else{

		while (i <= cen){ 
			tp[k] = v[i];
			i++; 
			k++;
		}
	}

	for (int k = inicio; k <= fin; k++)
		v[k] = tp[k] ;
}

template<class tipo_vector>
void Msort(vector<tipo_vector> &v, int inicio, int fin, unsigned long int &cp, unsigned modo){
	int cen; 

	if (inicio < fin){ 

		if(modo==0)
			cout << "Como inicio: " << inicio+1 << " es más pequeño que fin: " << fin+1 << ", dividimos la secuencia por la mitad." << endl;

		cen = (inicio + fin)/2;

		if(modo==0)
			cout << "Dividimos la secuencia desde la posicion " << inicio+1 << " hasta la " << cen+1 << "." << endl;

		Msort (v, inicio, cen, cp, modo);

		if(modo==0)
			cout << "Dividimos la secuencia desde la posicion " << cen+1 << " hasta la " << fin+1 << "." << endl;

		Msort (v, cen+1, fin, cp, modo);

		if(modo==0)
			cout << "Ahora mezclamos entre las posiciones " << cen+1 << " y " << fin+1 << "." << endl << endl;

		Mezcla (v, inicio, cen, fin, cp, modo);

		if(modo==0){
			cout << endl << "La secuencia en este paso queda así: " << endl;

            for (int i=0; i < v.size(); i++)
                cout << i+1 << ". " << v[i] << endl;

            cout << endl << "=============================";
            cin.ignore();
        }
	}
}

template<class tipo_vector>
unsigned long int mergesort(vector<tipo_vector> &v, unsigned modo){

	if (modo==0){
        cin.ignore();
        cout << "Secuencia antes de ejecutar mergesort: " << endl;
        for (int i=0; i < v.size(); i++)
            cout << i+1 << ". " << v[i] << endl;
        cout << endl;
    }

	unsigned long int cp=0;
	Msort(v,0,v.size()-1,cp, modo);

	if (modo==0){
        cout << "LA SECUENCIA YA ESTA ORDENADA" << endl << endl;
    }

	return cp;
}