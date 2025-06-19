#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Container {
protected:
    int coffee;
    int sugar;
    int cream;
    int water;
    int cup;
public:
    Container() { coffee = sugar = cream = water = cup = 5; }

    void fill() {
        cout << "��� ���� ä��ϴ�." << endl;
        coffee = sugar = cream = water = cup = 5;
    }

    bool canMakeCoffee(int c = 1, int s = 0, int cr = 0, int w = 1, int cp = 1) {
        return coffee >= c && sugar >= s && cream >= cr && water >= w && cup >= cp;
    }

    void consume(int c = 1, int s = 0, int cr = 0, int w = 1, int cp = 1) {
        coffee -= c;
        sugar -= s;
        cream -= cr;
        water -= w;
        cup -= cp;
    }

    void show() {
        cout.setf(ios::left);
        cout << setw(10) << "Coffee";
        cout.setf(ios::right);
        for (int i = 0; i < coffee; i++) cout << "*";
        cout << endl;
        cout.setf(ios::left);
        cout << setw(10) << "Sugar";
        cout.setf(ios::right);
        for (int i = 0; i < sugar; i++) cout << "*";
        cout << endl;
        cout.setf(ios::left);
        cout << setw(10) << "Cream";
        cout.setf(ios::right);
        for (int i = 0; i < cream; i++) cout << "*";
        cout << endl;
        cout.setf(ios::left);
        cout << setw(10) << "Water";
        cout.setf(ios::right);
        for (int i = 0; i < water; i++) cout << "*";
        cout << endl;
        cout.setf(ios::left);
        cout << setw(10) << "Cup";
        cout.setf(ios::right);
        for (int i = 0; i < cup; i++) cout << "*";
        cout << endl << endl;
    }
};

void printCentered(string text, int width, char fillChar = '-') {
    int padding = (width - text.length()) / 2;
    if (padding < 0) padding = 0;
    cout.setf(ios::left);
    cout << setfill(fillChar) << setw(padding + text.length()) << right << text;
    cout << setfill(fillChar) << setw(width - (padding + text.length())) << "" << endl;
    cout << setfill(' ');
}

class CoffeeVendingMachine {
    Container container;

public:
    void run() {
        string msg = "��ǰ Ŀ�� ���Ǳ� �մϴ�.";
        printCentered(msg, 20, '-');
        container.show();

        int select;
        while (true) {
            cout << "Ŀ��: 0, ����Ŀ��: 1, ��Ŀ��: 2, ä���: 3, ����: 4 >> ";
            cin >> select;

            switch (select) {
            case 0:
                if (container.canMakeCoffee(1, 0, 0, 1, 1)) {
                    cout << "Ŀ�� ���Խ��ϴ�." << endl;
                    container.consume(1, 0, 0, 1, 1);
                }
                else {
                    cout << "��ᰡ �����մϴ�." << endl;
                }
                break;

            case 1:
                if (container.canMakeCoffee(1, 1, 0, 1, 1)) {
                    cout << "����Ŀ�� ���Խ��ϴ�." << endl;
                    container.consume(1, 1, 0, 1, 1);
                }
                else {
                    cout << "��ᰡ �����մϴ�." << endl;
                }
                break;

            case 2:
                if (container.canMakeCoffee(2, 0, 1, 1, 1)) {
                    cout << "��Ŀ�� ���Խ��ϴ�." << endl;
                    container.consume(2, 0, 1, 1, 1);
                }
                else {
                    cout << "��ᰡ �����մϴ�." << endl;
                }
                break;

            case 3:
                container.fill();
                break;

            case 4:
                cout << "���Ǳ⸦ �����մϴ�." << endl << endl;
                return;

            default:
                cout << "�߸��� �Է��Դϴ�." << endl << endl;
                break;
            }

            cout << endl;
            container.show();
        }
    }
};

void problem12() {
    CoffeeVendingMachine vm;
    vm.run();
}
