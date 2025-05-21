#include <iostream>

using namespace std;

class Converter {
    float conv_rate;
public:
    Converter(float r) { this->conv_rate = r; }
    float convert(float source) { return source / conv_rate; }
};

class WonToDollar : public Converter {
private:
    float dollar_rate;
public:
    WonToDollar(float r) : Converter(r) {}
    void run() {
        float source = 0;
        cout << "원은 달러로 바꿉니다. 원을 입력하세요 >> ";
        cin >> source;
        cout << "변환 결과: " << convert(source) << " ($)" << endl;
    }
};

void problem1() {
    WonToDollar wd(1010);
    wd.run();
    cout << endl;
}
