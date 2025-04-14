#include <iostream>

using namespace std;

int add_(int* arr1, int* arr2 = nullptr, int size = 5) {
	int sum = 0;
	if (arr2 == NULL) {
		for (int i = 0; i < size; i++) {
			sum += arr1[i];
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			sum += arr1[i] + arr2[i];
		}
	}
	return sum;
}

void problem1_2() {
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 6, 7, 8, 9, 10 };
	int c = add_(a);
	int d = add_(a, b);
	cout << c << endl;
	cout << d << endl;
	cout << endl;
}
