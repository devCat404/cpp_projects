#include <iostream>

#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void problem13() {
    print("*****  승리장에 오신 것을 환영합니다.  *****\n");

    while (true) {
        int select;
        print("\n짬뽕: 1, 짜장면: 2, 군만두: 3, 종료: 4 >>> ");
        cin >> select;

        int option = 0;
        switch (select) {
        case 1:
            print("몇인분 : ");
            cin >> option;
            printf("짬뽕 %d인분 나왔습니다.\n", option);
            break;
        case 2:
            print("몇인분 : ");
            cin >> option;
            printf("짜장면 %d인분 나왔습니다.\n", option);
            break;
        case 3:
            print("몇인분 : ");
            cin >> option;
            printf("군만두 %d인분 나왔습니다.\n", option);
            break;
        case 4:
            print("영업 종료.\n");
            break;
        default:
            print("다시 입력\n");
            break;
        }

        if (select == 4) {
            print('\n');
            break;
        }
    }
}
