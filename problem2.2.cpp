#include <iostream>
#include <string>


#define loop(i, a, b) for(int i = a; i < b; i++)


using namespace std;

void problem2() {
    loop(i, 1, 10) {
        loop(j, 1, 10) {
            printf("%dx%d=%d\t", j, i, i * j);
        }
        cout << '\n';
    }
    cout << '\n';
}
