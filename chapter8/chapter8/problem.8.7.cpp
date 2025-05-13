#include <iostream>
                
using namespace std;

class BaseMemory {
private:
    char* mem;
protected:
    BaseMemory(int size) { mem = new char[size]; }
    void put(int idx, char val) {
        mem[idx] = val;
    }
    char get(int idx) { return mem[idx]; }
    void setMem(int memory_size) { mem = new char[memory_size]; }
};

class ROM : public BaseMemory {
private:
    int memory_size = 0;
public:
    ROM(int memory_size, char x[], int data_size) : BaseMemory(data_size) {
        setMem(memory_size);
        for (int i = 0; i < data_size; i++) {
            put(i, x[i]);
        }
    }
    ROM(int memory_size) : BaseMemory(0) {
        setMem(memory_size);
    }
    char read(int idx) { return get(idx); }
    void write(int idx, char val) {
        put(idx, val);
    }
};

class RAM : public ROM {
public:
    RAM(int memory_size) : ROM(memory_size) {}
};

void problem7() {
    char x[5] = { 'h', 'e', 'l', 'l', 'o' };
    ROM biosROM(1024 * 10, x, 5);
    RAM mainMemory(1024 * 1024);

    for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
    for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
    cout << endl << endl;
}
