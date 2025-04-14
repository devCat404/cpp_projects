#include <iostream>

using namespace std;

int big_(int a, int b, int max = 100) {
	if (a > b) {
		if (a > max) return max;
		else return a;
	}
	else if (b > a) {
		if (b > max) return max;
		else return b;
	}
}

void problem3_2() {
	int x = big_(3, 5);
	int y = big_(300, 60);
	int z = big_(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
	cout << endl;
}
