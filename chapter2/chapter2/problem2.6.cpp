#include <iostream>
#include <cstring>
#include <string>

#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void problem6() {
    char a[50];
    char b[50];

    print("첫 암호 입력: ");
    getchar();
    cin.getline(a, 50, '\n');
    print("암호 다시 입력: ");
    cin.getline(b, 50, '\n');

    if (strcmp(a, b) == 0) {
        print("같습니다.\n\n");
    }
    else {
        print("다릅니다.\n\n");
    }
}
