#include <iostream>
#include <vector>
#include <map>
                
using namespace std;

void problem13() {
	int choice, score;
	string name;
	map <string, int> dic;
	cout << "***** �������� ���α׷� HIGH SCORE�� �����մϴ�. *****" << endl;
	while (true) {
		cout << "�Է� : 1, ��ȸ : 2, ���� : 3 >> ";
		cin >> choice;
		if (choice == 1) {
			cout << "�̸��� ���� >> ";
			cin >> name >> score;
			dic[name] = score;
		}
		else if (choice == 2) {
			cout << "�̸� >> ";
			cin >> name;
			if (dic.find(name) == dic.end())
				cout << "ã�� �� �����ϴ�.";
			else
				cout << dic[name] << endl;
		}
		else if (choice == 3)
			break;
	}
	cout << "�����մϴ�.." << endl << endl;
}
