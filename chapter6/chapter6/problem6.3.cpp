#include <iostream>

using namespace std;

void problem3_2();

int big(int a, int b) {
	if (a > b) {
		if (a > 100) return 100;
		else return a;
	}
	else if (b > a) {
		if (b > 100) return 100;
		else return b;
	}
}

int big(int a, int b, int max) {
	if (a > b) {
		if (a > max) return max;
		else return a;
	}
	else if (b > a) {
		if (b > max) return max;
		else return b;
	}
}

void problem3() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
	cout << endl;
	problem3_2();
}
