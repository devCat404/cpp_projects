#include <iostream>

using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 0) { this->radius = radius; }
    void show() { cout << "radius = " << radius << " ÀÎ ¿ø" << endl; }
    friend void operator++ (Circle& self);
    friend Circle& operator++ (Circle& self, int radius);
};

void operator++ (Circle& self) {
    self.radius++;
}

Circle& operator++ (Circle& other, int none) {
    Circle temp;
    temp.radius = other.radius + 1;
    return temp;
}


void problem8() {
    Circle a(5), b(4);
    ++a; 
    b = a++; 
    a.show();
    b.show();
}
