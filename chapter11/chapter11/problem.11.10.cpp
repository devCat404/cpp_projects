#include <iostream>
#include <string>
                
using namespace std;

istream& prompt(istream& stream) {
    cout << "¾ÏÈ£? >> ";
    return stream;
}

void problem10() {
    string password;
    while (true) {
        cin >> prompt >> password;
        if (password == "C++") {
            cout << "login success!" << endl;
            break;
        }
        else {
            cout << "login fail. try again!" << endl;
        }
    }
    cout << endl;
}
