using namespace std;

template<class tipo_vector>
void quicksort(vector<tipo_vector> &v, int inicio, int final, unsigned long int &cp, unsigned modo){

    int i = inicio, j = final;
    tipo_vector tmp;
    tipo_vector pivote = v[(inicio + final)/2];

    while (i <= j) {

    	if (modo==0)
    		cout << "Como el centinela izquierda: " << i << " es menor o igual que el de la derecha: " << j << ", intercambiamos." << endl;

        while (v[i] < pivote){
        	if(modo==0)
        		cout << "Como el valor en el centinela izquierda: " << v[i] << " es menor que el del pivote: " << pivote << ", aumentamos el centinela." << endl;
            i++;
            cp++;
        }
            cp++;

        while (v[j] > pivote){
        	if(modo==0)
        		cout << "Como el valor en el centinela derecha: " << v[j] << " es mayor que el del pivote: " << pivote << ", disminuimos el centinela." << endl;
            j--;
            cp++;
        }
            cp++;

        if (i < j) {

        	if(modo==0)
        		cout << "Como el valor del centinela izquierda: " << i << " es menor o igual que el de la derecha: " << j << ", intercambiamos." << endl;

            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            i++;
            j--;
        }
        else if (i==j){
            i++;
            j--;
        }
    };

    if (inicio < j){

    	if(modo==0){
    		cout << "Como el centinela izquierda es menor que el de derecha, ordenamos el lado izquierdo." << endl;
    		cout << endl << "La secuencia en este paso queda así: " << endl;

                for (int i=0; i < v.size(); i++)
                    cout << i+1 << ". " << v[i] << endl;

                cout << endl << "=============================";
                cin.ignore();
    	}

        quicksort(v, inicio, j, cp, modo);
    }
    cp++;
    if (i < final){

    	if(modo==0){
    		cout << "Como el centinela izquierda es mayor que el de derecha, ordenamos el lado derecho." << endl;
    		cout << endl << "La secuencia en este paso queda así: " << endl;

                for (int i=0; i < v.size(); i++)
                    cout << i+1 << ". " << v[i] << endl;

                cout << endl << "=============================";
                cin.ignore();
    	}

        quicksort(v, i, final, cp, modo);
    }

}

template<class tipo_vector>
unsigned long int quicksort(vector<tipo_vector> &v, unsigned modo){
    unsigned long int cp=0;

    if (modo==0){
        cin.ignore();
        cout << "Secuencia antes de ejecutar quicksort: " << endl;
        for (int i=0; i < v.size(); i++)
            cout << i+1 << ". " << v[i] << endl;
        cout << endl;
    }

    quicksort(v, 0, v.size()-1, cp, modo);

    if (modo==0){
        cout << endl << "Secuencia tras el ejecutar quicksort: " << endl;
        for (int i=0; i < v.size(); i++)
            cout << i+1 << ". " << v[i] << endl;
        cout << endl << "=============================" << endl;
        cout << "LA SECUENCIA YA ESTA ORDENADA" << endl << endl;
    }

    return cp;
}