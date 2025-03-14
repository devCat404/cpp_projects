#include <iostream>

#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void problem4() {
    float flt[5];

    print("5개의 실수 입력: ");
    
    loop(i, 0, 5) {
        cin >> flt[i];
    }

    loop(i, 0, 5) {
        loop(j, 0, i) {
            int space;
            if (flt[i] < flt[j]) {
                space = flt[i];
                flt[i] = flt[j];
                flt[j] = space;
            }
        }
    }

    cout << "제일 큰 수: " << flt[4];
    printf("\n\n");
}
