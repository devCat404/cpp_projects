#include <iostream>

using namespace std;

class Person_ {
private:
	string name;
	int id;
	double weight;
public:
	Person_(int id, string name, double weight);
	void show() { cout << id << ": " << name << ", weight : " << weight << endl; }
};

Person_::Person_(int id = 1, string name = "Grace", double weight = 20.5) {
	this->id = id;
	this->name = name;
	this->weight = weight;
}

void problem2_2() {
	Person_ grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
	cout << endl;
}

