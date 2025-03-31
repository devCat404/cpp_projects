#include <iostream>
#include <string>

using namespace std;

class Person2 {
private:
    string name;
public:
    Person2() { name = " "; }
    Person2(string name) { this->name = name; }
    void setName(string name) { this->name = name; }
    string getName() { return name; }
};

class Family {
private:
    Person2* p;
    int size;
    string family;
public:
    Family(string name, int size);
    void show();
    void setName(int idx, string name);
    ~Family();
};

Family::Family(string n, int s) {
    family = n;
    size = s;
    p = new Person2 [size];
}

void Family::setName(int idx, string name) {
    p[idx].setName(name);
}

void Family::show() {
    cout << family << "가족은 다음과 같이 " << size << "명입니다.\n>> ";
    for (int i = 0; i < size; i++) {
        cout << p[i].getName() << ' ' << '/' << ' ';
    }
    cout << endl;
}

Family::~Family() {
    cout << "정보 삭제.\n" << endl;
}

void problem10() {
    Family* simpson = new Family("Simpson", 3);
    simpson->setName(0, "Mr. Simpson");
    simpson->setName(1, "Mrs. Simpson");
    simpson->setName(2, "Bart Simpson");
    simpson->show();
    delete simpson;
}
