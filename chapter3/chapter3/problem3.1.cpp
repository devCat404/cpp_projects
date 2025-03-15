#include <iostream>
        
#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++) 

using namespace std;

class Tower {
private:
    int height;

public:
    Tower() {
        height = 1;
    }

    Tower(int x) {
        height = x;
    }

    int getHeight() {
        return height;
    }
};

void problem1() {
    Tower myTower;
    Tower seoulTower(100);

    cout << "높이는 " << myTower.getHeight() << "미터\n" << endl;
    cout << "높이는 " << seoulTower.getHeight() << "미터\n" << endl;
}
