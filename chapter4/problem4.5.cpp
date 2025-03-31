#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void problem5() {

	srand((unsigned)time(0));
	getchar();

	string s;
	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다.)" << endl;
	while (true) {
		cout << ">>";
		getline(cin, s, '\n');

		if (s == "exit") {
			break;
		}

		int n = rand();
		int size = s.size();
		int rand_idx = n % size;
		char rand_str = rand() % 26 + 'a';
		s[rand_idx] = rand_str;

		cout << s << endl;
	}
	cout << endl;
}
