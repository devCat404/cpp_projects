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
        cout << "���� �޷��� �ٲߴϴ�. ���� �Է��ϼ��� >> ";
        cin >> source;
        cout << "��ȯ ���: " << convert(source) << " ($)" << endl;
    }
};

void problem1() {
    WonToDollar wd(1010);
    wd.run();
    cout << endl;
}
