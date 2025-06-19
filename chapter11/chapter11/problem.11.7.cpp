#include <iostream>
#include <iomanip>
#include <cctype>
#include <cmath>

using namespace std;

void problem7() {
	cout.setf(ios::left);

	for (int i = 0; i < 4; i++) {
		cout << setw(10) << "dec";
		cout << setw(10) << "hexa";
		cout << setw(10) << "char";

	}
	cout << endl;
	for (int i = 0; i < 4; i++) {
		cout << setw(10) << "___";
		cout << setw(10) << "____";
		cout << setw(10) << "____";
	}
	cout << endl;
	char c;
	for (int i = 0; i < 128; i++) {
		for (int j = 0; j < 4; j++) {
			cout << setw(10) << setfill(' ') << dec << i;
			cout << setw(10) << setfill(' ') << hex << i;
			if (isprint(i))
				c = (char)i;
			else c = '.';
			cout << setw(10) << setfill(' ') << c;
		}
		cout << endl;
	}
}
