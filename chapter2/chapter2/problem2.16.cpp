#include <iostream>
#include <cstring>

#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++)

using namespace std;

void problem16() {
    char sentence[1000];
    char alpha[1000];

    print("영문 텍스트 입력(끝은 ;, 최대 1000자): ");
    cin.getline(sentence, 1000, ';');

    int length = 0;
    int cnt[26] = { 0 };

    loop(i, 0, strlen(sentence)) {
        if (sentence[i] >= 'A') {
            sentence[i] = tolower(sentence[i]);
        }
        if (isalpha(sentence[i]) != 0) {
            alpha[i] = sentence[i];
            length++;
        }
    }

    cout << "\n총 알파벳 수: " << length << '\n';
    print('\n');

    loop(i, 0, length) {
        if (alpha[i] >= 'a' && alpha[i] <= 'z') {
            cnt[alpha[i] - 'a']++;  
        }
    }

    loop(i, 0, 26) {
        if (cnt[i] >= 0) {  
            printf("%c (%d) : ", (char)('a' + i), cnt[i]);
            for (int j = 0; j < cnt[i]; j++) {
                print("*");
            }
            print('\n');
        }
    }

    print('\n');
}
