#include <iostream>
#include <string>
        
#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++) 

using namespace std;

class CoffeeMachine {
private:
    int coffee = 0;
    int water = 0;
    int sugar = 0;

public:
    CoffeeMachine(int c, int w, int s) {
        coffee += c; water += w; sugar += s;
    }

    void espresso() {
        coffee -= 1; water -= 1;
    }

    void americano() {
        coffee -= 1; water -= 2;
    }

    void sugarCoffee() {
        coffee -= 1; water -= 2; sugar -= 1;
    }

    void fill() {
        coffee, water, sugar = 10;
    }

    void show() {
        cout << "커피머신 상태 >> 커피 : " << coffee << " 물 : " << water << " 설탕 : " << sugar << endl << endl;
    }
};

void problem4() {
    CoffeeMachine java(5, 10, 3);
    java.espresso();
    java.show();
    java.americano();
    java.show();
    java.sugarCoffee();
    java.show();
    java.fill();
    java.show();
}
