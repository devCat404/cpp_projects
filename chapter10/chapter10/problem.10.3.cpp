#include <iostream>
#include <vector>
                
using namespace std;

template <class T>
void reverseArray(T x[], int size)
{
	int j = size;
	int* p = new int[size];
	for (int i = 0; i < size; i++)
	{
		p[i] = x[--j];
	}
	for (int i = 0; i < size; i++)
	{
		x[i] = p[i];
	}
	delete[]p;
}

void problem3() {
	int x[] = { 1, 10, 100, 5, 4 };
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << x[i] << " ";
	}
	cout << endl << endl;
}
