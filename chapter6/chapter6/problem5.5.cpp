#include <iostream>

using namespace std;

class ArrayUtility {
public:
	static void intToDouble(int source[], double destination[], int size);
	static void doubleTOInt(double source[], int destination[], int size);
};

void ArrayUtility::intToDouble(int source[], double destination[], int size) {
	for (int i = 0; i < size; i++) {
		destination[i] = (double)source[i];
	}
}

void ArrayUtility::doubleTOInt(double source[], int destination[], int size) {
	for (int i = 0; i < size; i++) {
		destination[i] = (int)source[i];
	}
}

void problem5() {
	int x[] = { 1, 2, 3, 4, 5 };
	double y[5];
	double z[] = { 9.9, 8.8, 7.7, 6.6, 5.6 };

	ArrayUtility::intToDouble(x, y, 5);
	for (int i = 0; i < 5; i++) {
		cout << y[i] << ' ';
	}
	cout << endl;

	ArrayUtility::doubleTOInt(z, x, 5);
	for (int i = 0; i < 5; i++) {
		cout << x[i] << ' ';
	}
	cout << endl << endl;
}
