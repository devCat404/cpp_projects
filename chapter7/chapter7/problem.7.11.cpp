#include <iostream>
using namespace std;

class Stack {
private:
    int* p;
public:
    Stack() { p = new int[10]; for (int i = 0; i < 10; i++) p[i] = 0; }
    ~Stack() { delete[] p; }

    int getSize() {
        int size = 0;
        for (int i = 0; i < 10; i++) {
            if (p[i] != 0) size++;
        }
        return size;
    }

    friend Stack& operator<<(Stack& self, int num);
    friend void operator>>(Stack& self, int& destination); 
    friend bool operator!(Stack& self);
};

Stack& operator<<(Stack& self, int num) {
    for (int i = 0; i < 10; i++) {
        if (self.p[i] == 0) {
            self.p[i] = num;
            return self;
        }
    }
    cout << "FULL!" << endl;
    return self;
}

void operator>>(Stack& self, int& destination) {
    int index = self.getSize() - 1;
    if (index >= 0) {
        destination = self.p[index];
        self.p[index] = 0; 
    }
}

bool operator!(Stack& self) {
    return self.getSize() == 0;
}

void problem11() {
    Stack stack;
    stack << 3 << 5 << 10; 
    while (true) {
        if (!stack) break;
        int x;
        stack >> x;        
        cout << x << ' ';
    }
    cout << endl << endl;
}
