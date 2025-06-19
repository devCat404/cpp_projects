#include <iostream>
#include <limits>

using namespace std;

void problem3() {
    char buff;

    cout << "영어문장;한글문장 형식으로 입력하세요 (Ctrl+Z로 종료):" << endl;

    while (true) {
        cin.ignore(numeric_limits<streamsize>::max(), ';');

        while ((buff = cin.get()) != '\n' && buff != EOF) {
            cout.put(buff);
        }
        if (buff == EOF) {
            break;
        }

        cout << '\n';
    }
}
