#include <iostream>
#include <string>

using namespace std;

void problem3() {
	string k;
	cout << "문자열 입력: ";
	getchar();
	getline(cin, k, '\n');

	int cnt = 0;
	for (int i = 0; i < k.size(); i++) {
		if (k.at(i) == 'a') {
			cnt++;
		}
	}
	cout << "a의 개수: " << cnt << endl;

	int idx = 0;
	cout << "a의 인덱스: ";
	while ((idx = k.find('a', idx)) != -1) {
		cout << idx << ',';
		idx++;
	}
	cout << endl << endl;
}
