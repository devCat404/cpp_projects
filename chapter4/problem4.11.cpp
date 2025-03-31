#include <iostream>
#include <string>

using namespace std;

class Container {
    int size;
public:
    Container() { size = 10; }
    void fill() { size = 10; }
    void consume(int n) { size -= n; }
    int getSize() { return size; }
};

class CoffeeVendingMachine {
    Container tong[3];
    void fill() { for (int i = 0; i < 3; i++) { tong[i].fill(); } }
    void selectEspresso();
    void selectAmericano();
    void selectSugarCoffee();
    void show() { 
        cout << "커피: " << tong[0].getSize() << ',' << "물: " << tong[1].getSize() << ',' << "설탕: " << tong[2].getSize() << endl;
    }
public:
    void run();
};

void CoffeeVendingMachine::selectEspresso() {
    if (tong[0].getSize() < 1 || tong[1].getSize() < 1) {
        cout << "원료가 부족합니다." << endl;
    }
    tong[0].consume(1);
    tong[1].consume(1);
    cout << "에스프레소 드세요" << endl;
}

void CoffeeVendingMachine::selectAmericano() {
    if (tong[0].getSize() < 1 || tong[1].getSize() < 2) {
        cout << "원료가 부족합니다." << endl;
    }
    tong[0].consume(1);
    tong[1].consume(2); 
    cout << "아메리카노 드세요" << endl;
}

void CoffeeVendingMachine::selectSugarCoffee() {
    if (tong[0].getSize() < 1 || tong[1].getSize() < 2 || tong[2].getSize() < 1) {
        cout << "원료가 부족합니다." << endl;
    }
    tong[0].consume(1);
    tong[1].consume(2);
    tong[2].consume(1);
    cout << "설탕커피 드세요" << endl;
}


void CoffeeVendingMachine::run() {
    cout << "***** 커피자판기를 작동합니다. *****" << endl;
    while (true) {
        int select;
        cout << "메뉴를 눌러주세요 (1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기, 0:종료) >> ";
        cin >> select;

        switch (select) {
        case 1:
            selectEspresso();
            break;
        case 2:
            selectAmericano();
            break;
        case 3:
            selectSugarCoffee();
            break;
        case 4:
            show();
            break;
        case 5:
            fill();
            break;
        case 0:
            cout << "프로그램 종료.\n" << endl;
            return;
        default:
            cout << "잘못된 입력.\n" << endl;
            break;
        }
    }
}

void problem11() {
    CoffeeVendingMachine vender;
    vender.run();
}
