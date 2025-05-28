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
	cout << "���� �����ϰ� �����ϴ� ���α׷��Դϴ�. \n";
	while (true) {
		cout << "���� : 1, ���� : 2, ��κ��� : 3, ���� : 4 >> ";
		cin >> choice;
		if (choice == 1) {
			cout << "�����ϰ��� �ϴ� ���� �������� �̸��� >> ";
			cin >> radius >> name;
			v.push_back(new Circle(radius, name));
		}
		else if (choice == 2) {
			vector<Circle*>::iterator it;
			it = v.begin();
			cout << "�����ϰ��� �ϴ� ���� �̸��� >> ";
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
	cout << "���α׷��� �����մϴ�.." << endl << endl;
}
