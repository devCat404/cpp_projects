#include <iostream>
                
using namespace std;

void problem2() {
    char buff;
    int cnt = 0;

    cout << "���ڿ� �Է� [<enter>�� ���� ����]: ";

    while (1) {
        cin.get(buff);
        if (buff == ' ') {
            cnt++;
        }
        if (buff == '\n') {
            break;
        }
    }

    cout << "���� ����: " << cnt << endl << endl;
}
