#include <iostream>

using namespace std;

bool bigger(int a, int b, int& big) {
	if (a == b) {
		return true;
	}
	else {
		if (a > b) {
			big = a;
		}
		else {
			big = b;
		}
		return false;
	}
}

void problem4() {
	int a;
	int b;
	int big_n;

	cout << "�� �� �Է�: ";
	cin >> a;
	cin >> b;

	if (bigger(a, b, big_n)) {
		cout << "�� ���� ũ��� �����ϴ�." << endl << endl;
	}
	else {
		cout << "ū �� : " << big_n << endl << endl;
	}
}
