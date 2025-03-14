#include <iostream>

#define print(x) cout << x

using namespace std;

void problem3() {

    int a, b;

    print("두 수 입력: ");
    cin >> a;
    cin >> b;

    if (a > b)
        cout << "큰수: " << a << '\n';
    else
        cout << "큰수: " << b << '\n';

    print('\n');
}
