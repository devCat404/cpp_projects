#include <iostream>
using namespace std;

class SortedArray {
    int size;  
    int* p; 
    void sort(); 
public:
    SortedArray() { p = NULL, size = 0; }
    SortedArray(const SortedArray& src) { 
        this->size = src.size;
        p = new int[size];
        for (int i = 0; i < size; i++) {
            this->p[i] = src.p[i];
        }
    }
    SortedArray(int p[], int size) {
        this->size = size;
        this->p = new int[size];
        for (int i = 0; i < size; i++) this->p[i] = p[i];
    }
    ~SortedArray() { delete[] p; }
    SortedArray operator+ (SortedArray& other) {
        SortedArray result;
        result.size = this->size + other.size;
        result.p = new int[result.size];
        for (int i = 0; i < this->size; i++) result.p[i] = this->p[i];
        for (int i = 0; i < other.size; i++) result.p[this->size + i] = other.p[i];

        return result;
    }
    SortedArray& operator= (const SortedArray& source) {
        if (this == &source) return *this; 
        delete[] this->p;
        this->size = source.size;
        this->p = new int[this->size];
        for (int i = 0; i < size; i++) {
            p[i] = source.p[i];
        }
        return *this;
    }

    void show() {
        this->sort();
        cout << "{ ";
        for (int i = 0; i < size; i++) {
            cout << p[i] << " ";
        }
        cout << "}" << endl;
    }
};

void SortedArray::sort() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (p[i] < p[j]) {
                int temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void problem12() {
    int n[] = { 2, 20, 6 };
    int m[] = { 10, 7, 8, 30 };
    SortedArray a(n, 3), b(m, 4), c;

    c = a + b;

    a.show();
    b.show();
    c.show();

    cout << endl;
}
