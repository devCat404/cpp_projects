#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

class Random {
public:
    Random() {  
        srand((unsigned)time(0));
    }

    int next() {  
        return rand();
    }

    int nextInRange(int a, int b) {  
        return a + rand() % (b - a + 1);
    }
};

void problem5() {
    Random r;  

    cout << "\n-- 0에서 RAND_MAX(32767) 사이의 랜덤한 정수 10개 --" << endl;
    for (int i = 0; i < 10; i++) {
        cout << r.next() << " ";
    }
    cout << endl;

    cout << "\n\n-- 2에서 4 사이의 랜덤한 정수 10개 --" << endl;
    for (int i = 0; i < 10; i++) {
        cout << r.nextInRange(2, 4) << " ";
    }
    cout << endl << endl;
}
