#include <iostream>
#include <vector>
#include <map>
                
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius;
		this->name = name;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

void problem15() {
	int choice, radius;
	string name;
	vector<Circle*> v;
	cout << "원을 삭제하고 삽입하는 프로그램입니다. \n";
	while (true) {
		cout << "삽입 : 1, 삭제 : 2, 모두복기 : 3, 종료 : 4 >> ";
		cin >> choice;
		if (choice == 1) {
			cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
			cin >> radius >> name;
			v.push_back(new Circle(radius, name));
		}
		else if (choice == 2) {
			vector<Circle*>::iterator it;
			it = v.begin();
			cout << "삭제하고자 하는 원의 이름은 >> ";
			cin >> name;
			for (int i = 0; i < size(v); i++)
			{
				if (v[i]->getName() == name) {
					it = v.erase(it);
					break;
				}
				it++;
			}
		}
		else if (choice == 3) {
			for (int i = 0; i < size(v); i++) {
				cout << v[i]->getName() << endl;
			}
			cout << endl;
		}
		else if (choice == 4) {
			break;
		}
	}
	cout << "프로그램을 종료합니다.." << endl << endl;
}
