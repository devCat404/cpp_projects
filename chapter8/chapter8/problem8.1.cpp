#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
private:
	string name;
public:
	NamedCircle(int radius, string name) { setRadius(radius), this->name = name; }
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}
};

void problem1() {

	NamedCircle waffle(3, "waffle"); 
	waffle.show();
	cout << endl;
}
