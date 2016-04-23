#include "dni.hpp"
#include <vector>

using namespace std;

int main (void){

	vector<dni> vector_dni(3);

	for (int i=0;i<vector_dni.size();i++){
		vector_dni[i].set_random();
		cout << vector_dni[i].get_dni() << endl;
	}
}