using namespace std;

template<class tipo_vector>
unsigned long int shellsort(vector<tipo_vector> &v, unsigned modo){
	unsigned long int cp=0;

	if (modo==0){
        cin.ignore();
        cout << "Secuencia antes de ejecutar shellsort: " << endl;
        for (int i=0; i < v.size(); i++)
            cout << i+1 << ". " << v[i] << endl;
        cout << endl;
    }

    double alpha=0;

    if(modo==0){
		while(alpha >= 1 || alpha <= 0){
			cout << "Introduzca un alpha entre 0 y 1: ";
			cin >> alpha;
			cin.ignore();
		}
	}
	else{
		cout << "El alpha utilizado es 0,99." << endl;
		alpha = 0.99;
	}

	int delta = v.size();
	tipo_vector tp;

	while(delta > 1){
		delta = delta * alpha;
		
		for(unsigned i = delta; i<v.size(); i++){
			tipo_vector x = v[i];
			unsigned j = i;
			cp++;
			while((j >= delta) && (x < v[j-delta])){

				if (modo==0){
					cout << "Con alpha: " << alpha << " el delta ahora vale: " << delta << endl;
					cout << "Como el valor de la posicion " << i+1 << ": " << v[i] << " es menor que el de la posicion " << (j-delta)+1 << ": " << v[j-delta] << " intercambiamos y decrementamos delta." << endl;
					cin.ignore();
				}

				v[j] = v[j-delta];
				j = j - delta;
				cp++;
			}
			v[j] = x;

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
        cout << endl << "Secuencia tras el ejecutar shellsort: " << endl;
        for (int i=0; i < v.size(); i++)
            cout << i+1 << ". " << v[i] << endl;
        cout << endl << "=============================" << endl;
        cout << "LA SECUENCIA YA ESTA ORDENADA" << endl << endl;
    }

	return cp;
}