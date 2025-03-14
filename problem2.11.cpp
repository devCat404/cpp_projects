#include <iostream>

#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void problem11() {
    int n = 0;
    int sum = 0;
    print("끝 수 입력: ");
    cin >> n;

    loop(i, 0, n + 1) {
        sum += i;
    }

    cout << "1에서 " << n << "까지의 합은 " << sum << "입니다." << "\n";
    print('\n');
}
