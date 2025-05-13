#include <iostream>
#include <string>
                
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
    void setCircle(int radius, string name) { setRadius(radius), this->name = name; }
    void show() {
        cout << "반지름이 " << getRadius() << "인 " << name << endl;
    }
    string getName() { return this->name; }
    void setName(string name) { this->name = name; }
};

void problem2() {
    NamedCircle pizza[5];
    for (int i = 0; i < 5; i++) {
        int radius;
        string name;
        cout << i+1 <<": ";
        cin >> radius;
        getchar();
        getline(cin, name, '\n');
        pizza[i].setCircle(radius, name);
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < i; j++) {
            if (pizza[i].getRadius() < pizza[j].getRadius()) {
                int temp_radius;
                temp_radius = pizza[i].getRadius();
                pizza[i].setRadius(pizza[j].getRadius());
                pizza[j].setRadius(temp_radius);
                string temp_name;
                temp_name = pizza[i].getName();
                pizza[i].setName(pizza[j].getName());
                pizza[j].setName(temp_name);
            }
        }
    }
    cout << endl;
    cout << "가장 면적이 큰 피자는 " << pizza[4].getName() << ", 면적: " << pizza[4].getArea() << endl << endl;
}
