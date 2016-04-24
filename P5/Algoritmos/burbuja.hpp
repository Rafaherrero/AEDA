using namespace std;

template<class tipo_vector>
unsigned long int burbuja(vector<tipo_vector> &v, unsigned modo){

	tipo_vector tp;
	int i,j;
    unsigned long int cp = 0;

    if (modo==0){
        cin.ignore();
        cout << "Secuencia antes de ejecutar burbuja: " << endl;
        for (int i=0; i < v.size(); i++)
            cout << i+1 << ". " << v[i] << endl;
    }

	for (i=1; i<v.size(); i++){
   		for (j=0 ; j<v.size() - 1; j++){
            cp++;

            if (modo==0){
                cout << endl << "Realizo la comparación de las posiciones " << j+1 << " y " << j+2 << endl;
                cout << j+1 << ". " << v[j] << endl;
                cout << j+2 << ". " << v[j+1] << endl;
            }

    		if (v[j] > v[j+1]){

                 if (modo==0)
                    cout << "Como el valor de la posicion " << j+1 << ": " << v[j] << " es mayor que el de la posicion " << j+2 << ": " << v[j+1] << ", " << v[j] << " 'sube'." << endl;

				tp = v[j];   
    			v[j] = v[j+1];   
    			v[j+1] = tp;
    		}

            if (modo==0){
                cout << endl << "La secuencia en este paso queda así: " << endl;

                for (int i=0; i < v.size(); i++)
                    cout << i+1 << ". " << v[i] << endl;

                cout << endl << "=============================";
                cin.ignore();
            }
    	}
    }

    if (modo==0){
        cout << "LA SECUENCIA YA ESTA ORDENADA" << endl << endl;
    }

    return cp;
}