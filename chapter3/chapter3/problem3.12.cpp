#include "Ram.h"
        
#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++) 

using namespace std;

//구현부 (Ram.cpp)

Ram::Ram() { char mem[100 * 1024] = { 0 }; int size = 100 * 1024; };
Ram::~Ram() { print("메모리 제거됨\n\n"); };
char Ram::read(int address) { return mem[address]; };
void Ram::write(int address, char value) { mem[address] = value; };

//실현부 (main.cpp)

void problem12() {
    Ram ram;
    ram.write(100, 20);
    ram.write(101, 30);
    char res = ram.read(100) + ram.read(101);
    ram.write(102, res);
    cout << "102번지의 값 = " << (int)ram.read(102) << endl;
}
