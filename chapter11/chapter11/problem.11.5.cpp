#include <iostream>
#include <string>
                
using namespace std;

void problem5() {
    getchar();
    string cmd;
    cout << "cin.get(char*, int)로 문자열을 읽습니다." << endl;
    while (1) {
        cout << "종료하려면 exit을 입력하세요: ";
        getline(cin, cmd);
        if (cmd == "exit") {
            cout << "프로그램 종료...." << endl;
            break;
        }
    }
    cout << endl;
}
