#include <iostream>
#include <cstring>

using namespace std;

char& find(char a[], char c, bool& success) {
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	}
	success = false;
}

void problem6() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M을 찾을 수 없습니다." << endl;
	}
	loc = 'm';
	cout << s << endl << endl;
}
