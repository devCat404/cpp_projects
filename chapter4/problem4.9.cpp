#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    string tel;
public:
    Person();
    string getName() { return name; }
    string getTel() { return tel; }
    void set(string name, string tel);
};

Person::Person() { name = " ", tel = " "; }

void Person::set(string n, string t) { name = n;  tel = t; }

void problem9() {
    getchar();
    Person people[3];

    cout << "이름과 전화번호를 입력해 주세요.\n";

    for (int i = 0; i < 3; i++) {
        string n;
        string t;
        cout << "사람 " << i + 1 << ">> ";
        getline(cin, n, ' ');
        getline(cin, t, '\n');
        people[i].set(n, t);
    }

    string names[3];
    string tels[3];

    for (int i = 0; i < 3; i++) {
        names[i] = people[i].getName();
        tels[i] = people[i].getTel();
    }

    cout << "모든 사람의 이름은 >> ";
    for (int i = 0; i < 3; i++) {
        cout << names[i] << ' ';
    }
    cout << endl;
    string name_check;
    bool is_exist = false;

    cout << "전화번호 검색합니다. 이름 입력 >> ";
    getline(cin, name_check, '\n');
    for (int i = 0; i < 3; i++) {
        if (names[i] == name_check) {
            cout << "전화번호: " << tels[i] << endl;
            is_exist = true;
        }
    }
    if (!is_exist) {
        cout << "해당 목록이 존재하지 않습니다." << endl;
    }
    cout << endl;
}
