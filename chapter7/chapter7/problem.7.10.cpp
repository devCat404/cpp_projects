#include <iostream>
using namespace std;

class Statistics {
private:
    int* p;
public:
    Statistics() {
        p = new int[10];
        for (int i = 0; i < 10; i++) p[i] = 0;
    }
    ~Statistics() { delete[] p; }

    int getSize() {
        int size = 0;
        for (int i = 0; i < 10; i++) {
            if (p[i] != 0) size++;
        }
        return size;
    }

    friend bool operator! (Statistics& self);
    friend Statistics& operator<< (Statistics& self, int data);
    friend int operator>> (Statistics& self, int& destination);
    friend void operator~ (Statistics& self);
};

bool operator! (Statistics& self) {
    for (int i = 0; i < 10; i++) {
        if (self.p[i] != 0) return false;
    }
    return true;
}

Statistics& operator<< (Statistics& self, int data) {
    for (int i = 0; i < 10; i++) {
        if (self.p[i] == 0) {
            self.p[i] = data;
            return self;
        }
    }
    return self;
    cout << "FULL!";
}

int operator>> (Statistics& self, int& destination) {
    int sum = 0;
    int size = self.getSize();
    for (int i = 0; i < size; i++) {
        sum += self.p[i];
    }
    destination = (size != 0) ? (sum / size) : 0;
    return destination;
}

void operator~(Statistics& self) {
    cout << "[ ";
    for (int i = 0; i < self.getSize(); i++) {
        cout << self.p[i] << " ";
    }
    cout << "]" << endl;
}

void problem10() {
    Statistics stat;
    if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;

    int x[5];
    cout << "5 개의 정수를 입력하라>>";
    for (int i = 0; i < 5; i++) cin >> x[i];

    for (int i = 0; i < 5; i++) stat << x[i];
    stat << 100 << 200;
    ~stat;

    int avg;
    stat >> avg;
    cout << "avg=" << avg << endl;
    cout << endl;
}
