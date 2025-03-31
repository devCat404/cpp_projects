#include <iostream>

using namespace std;

class Sample {
private:
    int* p;
    int size;
public:
    Sample(int n) { size = n; p = new int[n]; }
    void read();
    void write();
    int big();
    ~Sample();
};

void Sample::read() {
    for (int i = 0; i < size; i++) {
        cin >> p[i];
    }
}

void Sample::write() {
    for (int i = 0; i < size; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;
}

int Sample::big() {
    for (int i = 0; i < size; i++) {
        int temp;
        for (int j = 0; j < i; j++) {
            if (p[i] < p[j]) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    return p[size - 1];
}

Sample::~Sample() {
    delete[] p;
    cout << "정수 배열 정보 삭제.\n" << endl;
}

void problem4() {
    Sample s(10);
    cout << "10개 정수 입력: ";
    s.read();
    s.write();
    cout << "가장 큰 수는 " << s.big() << endl;
}
