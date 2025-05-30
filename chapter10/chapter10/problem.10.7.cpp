#include <iostream>
                
using namespace std;

class Circle
{
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};

template <class T>
T bigger(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}


void problem7() {
	int a = 20, b = 50, c;
	c = bigger(a, b);

	cout << "20과 50중 큰 값은 " << c << endl;

	Circle waffle(10), pizza(20), y;

	y = bigger(waffle.getRadius(), pizza.getRadius());

	cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl << endl;
}
