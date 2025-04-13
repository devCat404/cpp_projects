#include <iostream>

using namespace std;

void half(double& n) {
	n = n * 0.5;
}

void problem2() {
	double n = 20;
	half(n);
	cout << n << endl << endl;
}
