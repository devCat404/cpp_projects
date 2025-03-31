#include <iostream>
#include <string>

using namespace std;

class Circle3 {
private:
    int radius;
    string name;
public:
    void setCircle(string name, int radius) { this->name = name; this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
    string getName() { return name; }
};

class CircleManger {
    Circle3* p;
    int size;
public:
    CircleManger(int size) { this->size = size; p = new Circle3[size]; }
    ~CircleManger();
    void searchByName();
    void searchByArea();
    void setting(string name[], int radius[]) {
        for (int i = 0; i < size; i++) { 
            p[i].setCircle(name[i], radius[i]); 
        } 
    }
};

void CircleManger::searchByName() {
    string circle;
    cout << "검색하고자 하는 원의 이름: ";
    cin >> circle;
    for (int i = 0; i < size; i++) {
        if (p[i].getName() == circle) {
            cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
        }
    }
}

void CircleManger::searchByArea() {
    int area;
    cout << "최소 면적을 정수로 입력하세요: ";
    cin >> area;
    cout << area << "보다 큰 원을 검색합니다." << endl;
    for (int i = 0; i < size; i++) {
        if (p[i].getArea() > area) {
            cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ',' << ' ';
        }
    }
    cout << endl;
}

CircleManger::~CircleManger() {
    delete[] p;
}

void problem12() {
    int num;
    cout << "원의 개수: ";
    cin >> num;
    CircleManger manager(num);

    string* circle_names = new string[num]; 
    int* s = new int[num];             

    getchar();

    for (int i = 0; i < num; i++) {
        cout << "원 " << i + 1 << "의 이름과 반지름 : ";
        getline(cin, circle_names[i], ' '); 
        cin >> s[i];                    
        getchar();
    }

    manager.setting(circle_names, s);

    manager.searchByName();
    manager.searchByArea();

    cout << endl;

    delete[] circle_names;
    delete[] s;
}
