#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <string>

using namespace std;

class SelectableRandom {
private:
    bool even;  

public:
    SelectableRandom(bool choice) {  
        even = choice;
        srand(time(0));
    }

    int next() {
        int n;
        do {
            n = rand() % 32768;  
        } while ((n % 2 == 0) != even);  
        return n;
    }

    int nextInRange(int a, int b) {
        if (a > b) swap(a, b);  

        int m;
        do {
            m = a + rand() % (b - a + 1);  
        } while ((m % 2 == 0) != even);  
        return m;
    }
};

void problem7() {
    int choice;
    cout << "짝수를 생성하려면 '1', 홀수를 생성하려면 '0'를 입력하세요: ";
    cin >> choice;

    string evenOdd;

    if (!choice) {
        evenOdd = "홀수";
    }
    else {
        evenOdd = "짝수";
    }

    SelectableRandom r(choice);  

    cout << "\n-- 0에서 32767 사이의 랜덤 " << evenOdd << "10개 --" << endl;
    for (int i = 0; i < 10; i++) {
        cout << r.next() << " ";
    }
    cout << endl;

    cout << "\n-- 0에서 32767 사이의 랜덤 " << evenOdd << "10개 --" << endl;
    for (int i = 0; i < 10; i++) {
        cout << r.nextInRange(2, 9) << " ";
    }
    cout << endl << endl;
}
