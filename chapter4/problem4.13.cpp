#include <iostream>
#include <string>

using namespace std;

class Histogram {
private:
    string sentence;
public:
    Histogram(string text) { sentence = text; }
    void put(string add_text) { sentence += add_text; }
    void putc(char c) { sentence += c; }
    void print() {
        cout << sentence << endl;

        int cnt[26] = { 0 };
        int alpha_cnt = 0;

        for (char c : sentence) {
            if (isalpha(c)) {
                c = tolower(c);
                cnt[c - 'a']++;
                alpha_cnt++;
            }
        }

        cout << "\n\n총 알파벳 수: " << alpha_cnt << endl << endl;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] >= 0) {
                cout << (char)('a' + i) << " (" << cnt[i] << "): ";
                for (int j = 0; j < cnt[i]; j++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
        cout << endl << endl;
    }
};

void problem13() {
    Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
    elvisHisto.put("falling in love with you");
    elvisHisto.putc('-');
    elvisHisto.put("Elvis Presely");
    elvisHisto.print();
}
