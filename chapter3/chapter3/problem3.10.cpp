#include "Calculator.h"

#include <iostream>
        
#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++) 

using namespace std;

//구현부(Calculator.cpp)

Add::Add() { int a, b = 0; };
void Add::setValue(int x, int y) { a = x; b = y; };
int Add::calculate() { return (a + b); };

Sub::Sub() { int a, b = 0; };
void Sub::setValue(int x, int y) { a = x; b = y; };
int Sub::calculate() { return (a - b); };

Mul::Mul() { int a, b = 0; };
void Mul::setValue(int x, int y) { a = x; b = y; };
int Mul::calculate() { return (a * b); };

Div::Div() { int a, b = 0; };
void Div::setValue(int x, int y) { a = x; b = y; };
int Div::calculate() { 
    if (b == 0) {
        print("0으로 나눌 수 없습니다.\n");
        return 0;
    }
    return (a / b); 
};

//실현부 (main.cpp)

void problem10() {
    Add a;
    Sub s;
    Mul m;
    Div d;

    while (true) {
        int n1, n2;
        char q;

        print("두 정수와 연산자 입력(종료 시 0 0 0 입력): ");
        cin >> n1;
        cin >> n2;
        cin >> q;

        if (n1 == 0 && n2 == 0 && q == '0') {
            print('\n');
            break;
        }

        switch (q) {
        case '+':
            a.setValue(n1, n2);
            cout << a.calculate() << endl;
            break;
        case '-':
            s.setValue(n1, n2);
            cout << s.calculate() << endl;
            break;
        case '*':
            m.setValue(n1, n2);
            cout << m.calculate() << endl;
            break;
        case '/':
            d.setValue(n1, n2);
            cout << d.calculate() << endl;
            break;
        default:
            print("잘못된 입력, 다시시도.");
            break;
        }
    }
}
