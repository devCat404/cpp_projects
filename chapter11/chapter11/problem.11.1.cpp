#include <iostream>
                
using namespace std;

void problem1() {
    char ch;
    int cnt = 0;

    cout << "���ڿ��� �Է��ϼ��� [<enter>�� ����]: ";

    while ((ch = cin.get()) != '\n') {
        if (ch == 'a') {
            cnt++;
        }
    }
    cout << "'a'�� ����: " << cnt << endl << endl;
}
