#include <iostream>

using namespace std;

void problem2_2();

class Person {
private:
	string name;
	int id;
	double weight;
public:
	Person() { id = 1, name = "Grace", weight = 20.5; }
	Person(int id, string name) { this->id = id, this->name = name, weight = 20.5; }
	Person(int id, string name, double weight) { this->id = id, this->name = name, this->weight = weight; }
	void show() { cout << id << ": " << name << ", weight : " << weight << endl; }
};

void problem2() {
	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
	cout << endl;
	problem2_2();
}

