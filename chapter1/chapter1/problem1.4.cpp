#include <iostream>

using namespace std;

void problem4() {
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    cout << '\n';
}
