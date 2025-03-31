#include <iostream>

using namespace std;

void problem2() {

	int* arr = new int[5];
	int sum = 0;
	float avg;

	cout << "정수 5개 입력 : ";

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 5; i++) {
		sum += arr[i];
	}

	avg = (float)sum / 5;

	cout << "평균 : " << avg << endl << endl;

	delete[] arr;
}
