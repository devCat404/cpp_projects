#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void problem8() {

    char arr[100];  
    char longest[20] = ""; 

    print("이름 5개를 ';'로 구분하여 입력: ");
    getchar();
    loop(i, 0, 5) {
        cin.getline(arr, 100, ';'); 
        cout << i + 1 << ':' << arr << '\n';

        
        if (strlen(arr) > strlen(longest)) {
            strcpy(longest, arr); 
        }
    }

    cout << "\n가장 긴 이름: " << longest << '\n';
    print('\n');
}
