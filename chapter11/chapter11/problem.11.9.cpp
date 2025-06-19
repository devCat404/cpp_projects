#include <iostream>
#include <string>
                
using namespace std;

class Phone {
    string name;
    string telnum;
    string address;
public:
    Phone(string name = "", string telnum = "", string address = "") {
        this->name = name;
        this->telnum = telnum;
        this->address = address;
    }
    friend istream& operator >> (istream& stream, Phone& a);
    friend ostream& operator << (ostream& stream, Phone a);
};

istream& operator >> (istream& stream, Phone& a) {
    cout << "이름: ";
    getline(cin, a.name);
    cout << "전화번호: ";
    getline(cin, a.telnum);
    cout << "주소: ";
    getline(cin, a.address);
    return stream;
}

ostream& operator << (ostream& stream, Phone a) {
    stream << "(" << a.name << ',' << a.telnum << ',' << a.address << ")";
    return stream;
}

void problem9() {
    getchar();
    Phone girl, boy;
    cin >> girl >> boy;
    cout << girl << endl << boy << endl << endl;
}
