#include <iostream>
#include <cstring>

#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void problem14() {
    int income = 0;

    while (true) {
        char coffee[100];
        int num;

        print("에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다.\n");
        print("주문: ");
        cin >> coffee >> num;
    
        if (strcmp(coffee, "에스프레소") == 0 ) {
            printf("%d원입니다.\n", 2000 * num);
            income += 2000 * num;
        }
        else if (strcmp(coffee, "아메리카노") == 0) {
            printf("%d원입니다.\n", 2300 * num);
            income += 2300 * num;
        }
        else if (strcmp(coffee, "카푸치노") == 0) {
            printf("%d원입니다.\n", 2500 * num);
            income += 2500 * num;
        }
        if (income >= 20000) {
            printf("오늘 %d원을 판매하여 영업종료 합니다.\n\n", income);
            break;
        }
    }
}
