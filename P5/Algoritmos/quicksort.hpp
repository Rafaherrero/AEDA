using namespace std;

template<class tipo_vector>
unsigned long int quicksort(vector<tipo_vector> &v, unsigned modo){
	unsigned long int cp=0;
	quicksort(v, 0, v.size()-1, cp, modo);
	return cp;
}

template<class tipo_vector>
void quicksort(vector<tipo_vector> &v, int inicio, int final, unsigned long int &cp, unsigned modo){

	cp++;
	if (inicio >= final)
		return;

	int mitad = inicio + (final-inicio)/2;
	tipo_vector pivote = v[mitad];

	swap(v[mitad], v[inicio]);

	int i = inicio+1;
	int j = final;

	while (i <= j){
		cp++;
		while(i <= j && v[i] <= pivote){
			i++;
			cp++;
		}
		cp++;
		while(v[j] > pivote){
			j--;
			cp++;
		}

		cp++;
		if (i < j)
			swap(v[i], v[j]);
	}

	swap(v[i-1], v[inicio]);
	int parte = i-1;

	quicksort(v, inicio, parte-1, cp, modo);
	quicksort(v, parte+1, final, cp, modo);
}