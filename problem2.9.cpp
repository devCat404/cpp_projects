#include <iostream>
#include <string>

#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void problem9() {
    string name, address;
    int age;

    print("이름: ");
    getchar();
    getline(cin, name);
    print("주소: ");
    getline(cin, address);
    print("나이: ");
    cin >> age;

    cout << "\n이름 : " << name << '\n' << "주소 : " << address << '\n' << "나이 : " << age << "세" << '\n';
    print('\n');
}
