#include <iostream>
                
using namespace std;

class LoopAdder {
    string name;
    int x, y, sum;
    void read();
    void write();
protected:
    LoopAdder(string name = "") {
        this->name = name;
    }
    int getX() { return x; }
    int getY() { return y; }
    virtual int calculate() = 0;
public:
    void run();
};

void LoopAdder::read() {
    cout << name << ": " << endl;
    cout << "처음 수에서 두번쨰 수까지 더합니다. 두 수를 입력하세요 >> ";
    cin >> x >> y;
}

void LoopAdder::write() {
    cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다." << endl;
}

void LoopAdder::run() {
    read();
    sum = calculate();
    write();
}

class ForLoopAdder : public LoopAdder {
public:
    ForLoopAdder(string name) : LoopAdder(name) {}
    int calculate() override {
        int for_sumation = 0;
        for (int i = getX(); i < getY() + 1; i++) {
            for_sumation += i;
        }
        return for_sumation;
    }
};

void problem3() {
    ForLoopAdder forLoop("For Loop");
    forLoop.run();
    cout << endl;
}
