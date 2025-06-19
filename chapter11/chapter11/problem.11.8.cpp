#include <iostream>
                
using namespace std;

class Circle {
    string name;
    int radius;
public:
    Circle(int radius = 1, string name = "") {
        this->radius = radius;
        this->name = name;
    }
    friend istream& operator >> (istream& stream, Circle& a);
    friend ostream& operator << (ostream& stream, Circle a);
};

istream& operator >> (istream& stream, Circle& a) {
    cout << "반지름 >> ";
    cin >> a.radius;
    cout << "이름 >> ";
    cin >> a.name;
    return stream;
}

ostream& operator << (ostream& stream, Circle a) {
    stream << "(" << a.radius << ',' << a.name << ")";
    return stream;
}

void problem8() {
    Circle d, w;
    cin >> d >> w;
    cout << d << w << endl << endl;
}
