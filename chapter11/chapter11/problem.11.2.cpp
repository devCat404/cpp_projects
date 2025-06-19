#include <iostream>
                
using namespace std;

void problem2() {
    char buff;
    int cnt = 0;

    cout << "문자열 입력 [<enter>를 눌러 종료]: ";

    while (1) {
        cin.get(buff);
        if (buff == ' ') {
            cnt++;
        }
        if (buff == '\n') {
            break;
        }
    }

    cout << "공백 개수: " << cnt << endl << endl;
}
