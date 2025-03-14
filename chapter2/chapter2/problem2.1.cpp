#include <iostream>

#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void problem1() {
    int num = 1;
    loop(i, 0, 10) {
        loop(i, 0, 10) {
            cout << num << '\t';
            num += 1;
        }
        print('\n');
    }
    print('\n');
}
