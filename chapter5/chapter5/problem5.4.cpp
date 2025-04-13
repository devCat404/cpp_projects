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

	cout << "두 수 입력: ";
	cin >> a;
	cin >> b;

	if (bigger(a, b, big_n)) {
		cout << "두 수의 크기는 같습니다." << endl << endl;
	}
	else {
		cout << "큰 수 : " << big_n << endl << endl;
	}
}
