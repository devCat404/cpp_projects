#include <iostream>

using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 0) { this->radius = radius; }
    void show() { cout << "radius = " << radius << " ÀÎ ¿ø" << endl; }
    friend void operator++ (Circle& self);
    friend Circle& operator++ (Circle& self, int radius);
    friend Circle operator+ (int n, Circle& other);
};

Circle operator+ (int n, Circle& other) {
    Circle temp;
    temp.radius = other.radius + n;
    return temp;
}

void problem9() {
    Circle a(5), b(4);
    b = 1 + a; 
    a.show();
    b.show();
    cout << endl;
}
