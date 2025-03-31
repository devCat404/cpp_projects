#include <iostream>

using namespace std;

class Circle {
private:
    int radius;
public:
    void setRadius(int radius);
    double getArea();
};

void Circle::setRadius(int r) {
    radius = r;
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}

void problem7() {
    Circle a[3];

    for (int i = 0; i < 3; i++) {
        int rad;
        cout << "원 " << i + 1 << "의 반지름: ";
        cin >> rad;
        a[i].setRadius(rad);
    }

    int cnt = 0;

    for (int i = 0; i < 3; i++) {
        if (a[i].getArea() > 100) {
            cnt++;
        }
    }

    cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다." << endl << endl;
}
