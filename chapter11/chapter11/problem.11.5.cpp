#include <iostream>
#include <string>
                
using namespace std;

void problem5() {
    getchar();
    string cmd;
    cout << "cin.get(char*, int)�� ���ڿ��� �н��ϴ�." << endl;
    while (1) {
        cout << "�����Ϸ��� exit�� �Է��ϼ���: ";
        getline(cin, cmd);
        if (cmd == "exit") {
            cout << "���α׷� ����...." << endl;
            break;
        }
    }
    cout << endl;
}
