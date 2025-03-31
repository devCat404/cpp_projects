#include <iostream>

using namespace std;

class Circle2 {
private:
    int radius;
public:
    void setRadius(int radius);
    double getArea();
};

void Circle2::setRadius(int r) {
    radius = r;
}

double Circle2::getArea() {
    return 3.14 * radius * radius;
}

void problem8() {

    int n;
    cout << "원의 개수 >> ";
    cin >> n;

    Circle2* a = new Circle2[n];

    for (int i = 0; i < n; i++) {
        int rad;
        cout << "원 " << i + 1 << "의 반지름: ";
        cin >> rad;
        a[i].setRadius(rad);
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (a[i].getArea() > 100) {
            cnt++;
        }
    }

    cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다." << endl << endl;
}
