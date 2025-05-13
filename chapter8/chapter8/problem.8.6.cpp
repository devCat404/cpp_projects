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
            cout << "������ ���� á���ϴ�." << endl;
            exit(1);
        }
        else {
            put(top, val);
            top++;
        }
    }
    int pop() {
        if (top <= 0) {
            cout << "������ ����ֽ��ϴ�." << endl;
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
    cout << "���ÿ� ������ 5���� ������ �Է��Ͽ��� : ";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        mStack.push(n);
    }
    cout << "���� �뷮 : " << mStack.capacity() << ", ���� ũ��: " << mStack.length() << endl;
    cout << "������ ��� ���Ҹ� pop�Ͽ� ���: ";
    while (mStack.length()) {
        cout << mStack.pop() << ' ';
    }
    cout << endl << "������ ���� ũ��: " << mStack.length() << endl << endl;
}
