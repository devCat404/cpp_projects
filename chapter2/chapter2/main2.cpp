#include <iostream>

#define print(x) cout << x

using namespace std;

void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();
void problem11();
void problem12();
void problem13();
void problem14();
void problem15();
void problem16();

int main() {
    while (true) {
        int choice;

        print("문제 선택 (1~16), 17을 눌러 종료: ");
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
            problem5(); 
            break;
        case 6: 
            problem6(); 
            break;
        case 7: 
            problem7(); 
            break;
        case 8: 
            problem8();
            break;
        case 9: 
            problem9(); 
            break;
        case 10: 
            problem10(); 
            break;
        case 11: 
            problem11();
            break;
        case 12: 
            problem12(); 
            break;
        case 13: 
            problem13();
            break;
        case 14: 
            problem14(); 
            break;
        case 15: 
            problem15(); 
            break;
        case 16: 
            problem16();
            break;
        case 17:
            print("프로그램 종료.");
            return 0;
        default:
            print("잘못된 입력.");
            return 0;
        }
    }

    return 0;
}
