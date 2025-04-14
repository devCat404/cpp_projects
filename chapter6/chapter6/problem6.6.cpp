#include <iostream>

using namespace std;

class ArrayUtility2 {
private:
	static int* p;
	static int* q;
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::p = nullptr;
int* ArrayUtility2::q = nullptr;

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	p = new int[2 * size];
	for (int i = 0; i < size; i++) {
		p[i] = s1[i];
	}
	for (int j = 0; j < size; j++) {
		p[j + size] = s2[j];
	}
	return p;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	q = new int[size];
	retSize = 0;

	for (int i = 0; i < size; i++) {
		bool found = false;
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j]) {
				found = true;
				break;
			}
		}
		if (!found) {
			q[retSize++] = s1[i];
		}
	}
	return q;
}


void problem6() {
	int x[5];
	int y[5];
	cout << "정수 5개 입력: ";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}
	cout << "정수 5개 입력: ";
	for (int i = 0; i < 5; i++) {
		cin >> y[i];
	}

	cout << endl;

	int* p1;
	p1 = ArrayUtility2::concat(x, y, 5);
	cout << "합친 정수 배열: ";
	for (int i = 0; i < 5; i++) {
		cout << p1[i] << ' ';
	}
	cout << endl << endl;

	int* p2;
	int size;
	p2 = ArrayUtility2::remove(x, y, 5, size);
	cout << "배열 x[]에서 y[]를 뺀 결과(개수는 " << size << ") : ";
	for (int i = 0; i < size; i++) {
		cout << p2[i] << ' ';
	}
	cout << endl << endl;
}
