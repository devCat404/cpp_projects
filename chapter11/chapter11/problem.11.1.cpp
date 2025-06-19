#include <iostream>
                
using namespace std;

void problem1() {
    char ch;
    int cnt = 0;

    cout << "문자열을 입력하세요 [<enter>로 종료]: ";

    while ((ch = cin.get()) != '\n') {
        if (ch == 'a') {
            cnt++;
        }
    }
    cout << "'a'의 개수: " << cnt << endl << endl;
}
