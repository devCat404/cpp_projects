#include <iostream>
#include <limits>

using namespace std;

void problem3() {
    char buff;

    cout << "�����;�ѱ۹��� �������� �Է��ϼ��� (Ctrl+Z�� ����):" << endl;

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
