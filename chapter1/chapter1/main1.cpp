#include <iostream>

#define print(x) cout << x

using namespace std;

void problem1();
void problem2();
void problem3();
void problem4();

int main() {
    while (true) {
        int choice;

        print(" 문제 선택(1~4), 5번을 눌러 종료: ");
        cin >> choice;

        switch (choice) {
        case 1: 
            problem1(); 
            break;
        case 2: 
            problem2(); 
            break;
        case 3:
            problem3();
            break;
        case 4:
            problem4();
            break;
        case 5:
            print("프로그램 종료.");
            return 0;
        default: 
            print("잘못된 입력");
            return 0;
        }
    }

    return 0;
}
