#include <iostream>

using namespace std;

class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r) { radius = r; }

	void swap(Circle& b) {
		int temp_radius;
		temp_radius = this->radius;
		radius = b.radius;
		b.radius = this->radius;
	}
	
	int getArea() {
		return 3.14 * radius * radius;
	}

	int getRadius() {
		return radius;
	}
};

Circle::Circle() : Circle(1) {}

void problem1() {
	Circle pizza;
	Circle donut(4);

	int rad_pizza = pizza.getRadius();
	int rad_donut = donut.getRadius();

	int area_pizza = pizza.getArea();
	int area_donut = donut.getArea();

	cout << "¹Ù²î±â ÀüÀÇ µÎ Circle °´Ã¼ÀÇ ¹ÝÁö¸§°ú ³ÐÀÌ: " << "A: (" << rad_pizza << ", " << area_pizza << ") / B: (" << rad_donut << ", " << area_donut << ")" << endl;

	pizza.swap(donut);

	int rad_pizza2 = pizza.getRadius();
	int rad_donut2 = donut.getRadius();

	int area_pizza2 = pizza.getArea();
	int area_donut2 = donut.getArea();

	cout << "¹Ù²ï ÈÄÀÇ µÎ Circle °´Ã¼ÀÇ ¹ÝÁö¸§°ú ³ÐÀÌ: " << "A: (" << rad_pizza2 << ", " << area_pizza2 << ") / B: (" << rad_donut2 << ", " << area_donut2 << ")" << endl << endl;
}
