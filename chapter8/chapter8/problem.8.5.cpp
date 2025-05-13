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
            cout << "큐가 가득찼습니다." << endl;
            exit(1);
        }
        else {
            put(back, val);
            back++;
        }
    }
    int dequeue() {
        if (back <= 0) {
            cout << "큐가 비어있습니다." << endl;
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
    cout << "큐에 삽일할 5개의 정수 입력: ";
    for (int i = 0; i < 5; i++) {
        cin >> n;
        mQ.enqueue(n);
    }
    cout << "큐의 용량: " << mQ.capacity() << ", 큐의 크기: " << mQ.length() << endl;
    cout << "큐의 원소를 순서대로 제거하여 출력한다 : ";
    while (mQ.length() != 0) {
        cout << mQ.dequeue() << " ";
    }
    cout << endl << "큐의 현재 크기: " << mQ.length() << endl << endl;
}
