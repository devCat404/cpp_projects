#include <iostream>
                
using namespace std;

class AbstractGate {
protected:
    bool x, y;
public:
    void set(bool x, bool y) {
        this->x = x;
        this->y = y;
    }
    virtual bool operation() = 0;
};

class ANDGate : public AbstractGate {
public:
    ANDGate() {}
    bool operation() override {
        if (x && y) {
            return true;
        }
        return false;
    }
};

class ORGate : public AbstractGate {
public:
    ORGate() {}
    bool operation() override {
        if (x || y) {
            return true;
        }
        return false;
    }
};

class XORGate : public AbstractGate {
public:
    XORGate() {}
    bool operation() override {
        if (x != y) {
            return true;
        }
        return false;
    }
};

void problem5() {
    ANDGate andGate;
    ORGate orGate;
    XORGate xorGate;

    andGate.set(true, false);
    orGate.set(true, false);
    xorGate.set(true, false);
    cout.setf(ios::boolalpha);
    cout << andGate.operation() << endl;
    cout << orGate.operation() << endl;
    cout << xorGate.operation() << endl << endl;
}
