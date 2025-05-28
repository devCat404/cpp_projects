#include <iostream>
#include <vector>
#include <map>
                
using namespace std;

void problem13() {
	int choice, score;
	string name;
	map <string, int> dic;
	cout << "***** 점수관리 프로그램 HIGH SCORE을 시작합니다. *****" << endl;
	while (true) {
		cout << "입력 : 1, 조회 : 2, 종료 : 3 >> ";
		cin >> choice;
		if (choice == 1) {
			cout << "이름과 점수 >> ";
			cin >> name >> score;
			dic[name] = score;
		}
		else if (choice == 2) {
			cout << "이름 >> ";
			cin >> name;
			if (dic.find(name) == dic.end())
				cout << "찾을 수 없습니다.";
			else
				cout << dic[name] << endl;
		}
		else if (choice == 3)
			break;
	}
	cout << "종료합니다.." << endl << endl;
}
