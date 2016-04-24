using namespace std;

template<class tipo_vector>
unsigned long int seleccion(vector<tipo_vector> &v, unsigned modo){

	tipo_vector tp;
	unsigned min;
	unsigned long int cp = 0;

	if (modo==0){
        cin.ignore();
        cout << "Secuencia antes de ejecutar seleccion: " << endl;
        for (int i=0; i < v.size(); i++)
            cout << i+1 << ". " << v[i] << endl;
    }

	for (int i = 0; i < v.size()-1; i++){ 
		min = i;
		for (int j = i+1; j < v.size(); j++){
			cp++;
			
			if (modo==0){
                cout << endl << "Realizo la comparación de las posiciones " << min+1 << " y " << j+1 << endl;
                cout << min+1 << ". " << v[min] << endl;
                cout << j+1 << ". " << v[j] << endl;
            }

			if (v[j] < v[min]){

				if (modo==0){
					cout << "Como el valor de la posicion " << j+1 << ": " << v[j] << " es menor que el de la posicion " << min+1 << ": " << v[min+1] << ", ahora la posicion " << j+1 << ": " << v[j] << " es el valor minimo." << endl;
				}

				min = j;
			}
		}

		tp = v[min];
		v[min] = v[i];
		v[i] = tp;

		if (modo==0){
			cout << "Intercambio las posiciones " << min+1 << ": " << v[min] << " y " << i+1 << ": " << v[i] << ". " << endl;
			cout << endl << "La secuencia en este paso queda así: " << endl;

                for (int i=0; i < v.size(); i++)
                    cout << i+1 << ". " << v[i] << endl;

                cout << endl << "=============================";
                cin.ignore();
		}
	}

	if (modo==0){
        cout << "LA SECUENCIA YA ESTA ORDENADA" << endl << endl;
    }
    
	return cp;
}