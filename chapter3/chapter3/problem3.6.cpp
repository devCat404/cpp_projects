#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

class EvenRandom {
public:
    EvenRandom() {  
        srand((unsigned)time(0));
    }

    int next() {
        int n;
        do {
            n = rand();  
        } while (n % 2 != 0);  
        return n;
    }

    int nextInRange(int a, int b) {
        if (a > b) swap(a, b);  

        int m;
        do {
            m = a + rand() % (b - a + 1);  
        } while (m % 2 != 0);  
        return m;
    }
};

void problem6() {
    EvenRandom r;  

    cout << "\n-- 0¿¡¼­ RAND_MAX(32767) »çÀÌÀÇ ·£´ý Â¦¼ö 10°³ --" << endl;
    for (int i = 0; i < 10; i++) {
        cout << r.next() << " ";
    }
    cout << endl << endl;

    cout << "-- 2¿¡¼­ 10 »çÀÌÀÇ ·£´ý Â¦¼ö 10°³ --" << endl;
    for (int i = 0; i < 10; i++) {
        cout << r.nextInRange(2, 10) << " ";
    }
    cout << endl << endl;
}
