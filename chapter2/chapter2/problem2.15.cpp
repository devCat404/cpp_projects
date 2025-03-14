#include <iostream>

#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void problem15() {
    while (true) {
        int option = 0;

        print("계산기 이용시 1, 종료시 0 입력: ");
        cin >> option;

        if (option == 0) {
            printf("프로그램 종료.\n\n");
            break;
        }

        int a;
        int b;
        char p;

        print("연산 식 입력: ");
        cin >> a;
        getchar();
        cin >> p;
        getchar();
        cin >> b;

        int res = 0;


        switch (p) {
        case '+' :
            res = a + b;
            printf("%d %c %d= %d\n\n", a, p, b, res);
            break;
        case '*':
            res = a * b;
            printf("%d %c %d= %d\n\n", a, p, b, res);
            break;
        case '-':
            res = a - b;
            printf("%d %c %d= %d\n\n", a, p, b, res);
            break;
        case '/':
            res = a / b;
            printf("%d %c %d= %d\n\n", a, p, b, res);
            break;
        case '%':
            res = a % b;
            printf("%d %c %d= %d\n\n", a, p, b, res);
            break;
        default :
            break;
        }
    }
}
