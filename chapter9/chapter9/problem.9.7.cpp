#include <iostream>
                
using namespace std;

class Shape {
protected:
    string name;
    int width, height;
public:
    Shape(string n = "", int w = 0, int h = 0) { name = n, width = w, height = h; }
    virtual double getArea() { return 0; }
    string getName() { return name; }
};

class Oval : public Shape {
private:
    
public:
    Oval(string name, int width, int height) : Shape(name, width, height) {}
    double getArea() override {
        return 3.14 * width * height;
    }
};

class Rect : public Shape {
private:

public:
    Rect(string name, int width, int height) : Shape(name, width, height) {}
    double getArea() override {
        return width * height;
    }
};

class Triangular : public Shape {
private:

public:
    Triangular(string name, int width, int height) : Shape(name, width, height) {}
    double getArea() override {
        return 0.5 * width * height;
    }
};

void problem7() {
    Shape* p[3];
    p[0] = new Oval("ºó´ë¶±", 10, 20);
    p[1] = new Rect("Âû¶±", 30, 40);
    p[2] = new Triangular("Åä½ºÆ®", 30, 40);
    for (int i = 0; i < 3; i++) {
        cout << p[i]->getName() << "ÀÇ ³ÐÀÌ´Â " << p[i]->getArea() << endl;
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        delete p[i];
    }
}
