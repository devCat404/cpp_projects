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

class MyQueue : public BaseArray {
private:
    int front;
    int back;
public:
    MyQueue(int capacity) : BaseArray(capacity), front(0), back(0) {}
    int capacity() { return getCapacity(); }
    int length() { return back; }
    void enqueue(int val) {
        if (back >= getCapacity()) {
            cout << "ť�� ����á���ϴ�." << endl;
            exit(1);
        }
        else {
            put(back, val);
            back++;
        }
    }
    int dequeue() {
        if (back <= 0) {
            cout << "ť�� ����ֽ��ϴ�." << endl;
            exit(1);
        }
        else {
            back--;
            int front_val = get(front);
            front++;
            return front_val;
        }
    }
};

void problem5() {
    MyQueue mQ(100);
    int n;
    cout << "ť�� ������ 5���� ���� �Է�: ";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        mQ.enqueue(n);
    }
    cout << "ť�� �뷮: " << mQ.capacity() << ", ť�� ũ��: " << mQ.length() << endl;
    cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ� : ";
    while (mQ.length() != 0) {
        cout << mQ.dequeue() << " ";
    }
    cout << endl << "ť�� ���� ũ��: " << mQ.length() << endl << endl;
}
