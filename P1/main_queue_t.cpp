#include "common.hpp"
#include "queue_t.hpp"

using namespace std;

int main(void)
{
	queue_t A(10);

	for (int i=0; i < A.size(); i++){
		A.push(i+2*i);
	}

	cout << A.front() << endl;
	cout << A.back() << endl;

	for (int i=0; i < A.size(); i++){
		cout << A.pop() << endl;
	}

	if (A.empty())
		cout << "La cola esta vacia" << endl;
}