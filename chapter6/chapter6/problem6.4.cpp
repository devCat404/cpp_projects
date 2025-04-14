#include <iostream>

using namespace std;

class MyVector {
private:
	int* mem;
	int size;
public:
	MyVector(int n = 100, int val = 0);
	~MyVector() { delete[] mem; }
	void show();
};

MyVector::MyVector(int n, int val) {
	mem = new int[n];
	size = n;
	for (int i = 0; i < size; i++) {
		mem[i] = val;
	}
}

void MyVector::show() {
	for (int i = 0; i < size; i++) {
		cout << mem[i];
	}
	cout << endl;
}

void problem4() {
	MyVector vector1, vector2(50), vector3(50, 3);
	cout << "vector1 : ";
	vector1.show();
	cout << endl;
	cout << "vector2 : ";
	vector2.show();
	cout << endl;
	cout << "vector3 : ";
	vector3.show();
	cout << endl;
}
