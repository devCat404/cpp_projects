#include <iostream>
#include <string>
#include <cstring>

#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void problem10() {
    char a[10];

    print("문자열 입력: ");
    cin >> a;

    int len = strlen(a);

    loop(i, 0, len + 1) {
        loop(j, 0, i) {
            printf("%c", a[j]);
        }
        print('\n');
    }
    print('\n');
}
