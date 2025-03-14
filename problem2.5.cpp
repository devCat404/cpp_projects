#include <iostream>
#include <cstring>

#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void problem5() {
    char sentence[100];
    int length = strlen(sentence);

    print("문자열 입력: ");
    getchar();
    cin.getline(sentence, 100, '\n');

    int cnt = 0;
    loop(i, 0, length) {
        if (sentence[i] == 'x') {
            cnt++;
        }
    }
    printf("x의 개수는 %d\n\n", cnt);
}
