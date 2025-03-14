#include <iostream>
#include <string>

using namespace std;

void problem2() {
    string dep;
    int id;
    string dream;
    cout << "학과 입력: ";
    getchar();
    getline(cin, dep);
    cout << "학번 입력: ";
    cin >> id;
    cout << "희망 직업 입력: ";
    getchar();
    getline(cin, dream);

    cout << "\n학과 : " << dep << '\n' << "학번 : " << id << '\n' << "희망 직업 : " << dream << '\n' << '\n';
}
