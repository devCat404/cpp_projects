#include <iostream>
                
using namespace std;

template <class T>
T* concat(T a[], int sizea, T b[], int sizeb) {
	T* p = new T[sizea + sizeb];
	for (int i = 0; i < sizea; i++)
		p[i] = a[i];
	for (int i = 0; i < sizeb; i++)
		p[i + sizea] = b[i];

	return p;
}

void problem5() {
	int xInt[] = { 1, 2, 3, 4, 5 }; 
	int yInt[] = { 6, 7, 8, 9, 10 };

	int xSize = size(xInt);
	int ySize = size(yInt);
	int sizeT = xSize + ySize;
	auto* p = concat(xInt, xSize, yInt, ySize);

	for (int i = 0; i < sizeT; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	delete[] p;

	double xDouble[] = { 1.1, 2.2, 3.3, 4.4, 5.5 }; 
	double yDouble[] = { 6.6, 7.7, 8.8, 9.9, 10.1 };

	xSize = size(xDouble);
	ySize = size(yDouble);
	sizeT = xSize + ySize;
	auto* q = concat(xDouble, xSize, yDouble, ySize);

	for (int i = 0; i < sizeT; i++)
	{
		cout << q[i] << " ";
	}
	cout << endl << endl;
	delete[] q;
}
