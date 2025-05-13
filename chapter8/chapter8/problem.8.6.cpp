#include <iostream>
                
using namespace std;

class BaseArray {
private:
    int capacity;
    int* mem;
protected:
    BaseArray(int capacity = 100) {
        this->capacity = capacity;
        mem = new int[capacity];
    }
    ~BaseArray() { delete[] mem; }
    void put(int index, int val) { mem[index] = val; }
    int get(int index) { return mem[index]; }
    int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {
private:
    int top;
public:
    MyStack(int capacity) : BaseArray(capacity), top(0) {}
    int capacity() { return getCapacity(); }
    int length() { return top; }
    void push(int val) {
        if (top >= getCapacity()) {
            cout << "스택이 가득 찼습니다." << endl;
            exit(1);
        }
        else {
            put(top, val);
            top++;
        }
    }
    int pop() {
        if (top <= 0) {
            cout << "스택이 비어있습니다." << endl;
            exit(0);
        }
        else {
            top--;
            int pop_val = get(top);
            return pop_val;
        }
    }
};


void problem6() {
    MyStack mStack(100);
    int n;
    cout << "스택에 삽입할 5개의 정수를 입력하여라 : ";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        mStack.push(n);
    }
    cout << "스택 용량 : " << mStack.capacity() << ", 스택 크기: " << mStack.length() << endl;
    cout << "스택의 모든 원소를 pop하여 출력: ";
    while (mStack.length()) {
        cout << mStack.pop() << ' ';
    }
    cout << endl << "스택의 현재 크기: " << mStack.length() << endl << endl;
}
