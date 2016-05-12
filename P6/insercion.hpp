using namespace std;

template<class tipo_vector>
unsigned long int insercion(vector<tipo_vector> &v, unsigned modo){
	
	tipo_vector tp;
	int i,j;
	unsigned long int cp = 0;

	if (modo==0){
		cin.ignore();
		cout << "Secuencia antes de ejecutar insercion: " << endl;
		for (int i=0; i < v.size(); i++)
			cout << i+1 << ". " << v[i] << endl;
	}

	for (i=1; i<v.size(); i++){
		
		tp = v[i];
		j = i - 1;

		if (modo==0){
			cout << endl << "Realizo la comparación de las posiciones " << j+1 << " y " << i+1 << endl;
			cout << j+1 << ". " << v[j] << endl;
			cout << i+1 << ". " << v[i] << endl << endl;
		}
		cp++;
		while ((v[j] > tp) && (j >= 0)){
			cp++;
			if (modo==0)
				cout << "Como el valor de la posicion " << j+1 << ": " << v[j] << " es mayor que el de la posicion " << j+2 << ": "<< tp << ", inserto el mayor en la posicion siguiente." << endl;

       		v[j+1] = v[j];

       		if (modo==0)
    	    	cout << "Decremento el centinela a la posicion " << j+1 << endl;

    	    j--;    	    
    	}

    	if (modo==0)
    		cout << "Asigno el valor de la posicion " << i+1 << ": " << tp << " a la posicion " << j+2 << ": " << v[j+1] << endl << endl;

    	v[j+1] = tp;

    	if (modo==0){
    		cout << "La secuencia en este paso queda así: " << endl;

    		for (int i=0; i < v.size(); i++)
				cout << i+1 << ". " << v[i] << endl;

			cout << endl << "=============================";
			cin.ignore();
		}
	}

	if (modo==0)
		cout << "LA SECUENCIA YA ESTA ORDENADA" << endl << endl;

	return cp;
}