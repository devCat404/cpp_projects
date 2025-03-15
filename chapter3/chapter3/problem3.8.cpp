#include <iostream>
#include <string>
        
#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++) 

using namespace std;

class Integer {
private:
    int n;

public:
    Integer(int x) {
        n = x;
    }

    Integer(string y) {
        n = stoi(y);
    }

    int get() {
        return n;
    }

    void set(int k) {
        n = k;
    }

    int isEven() {
        return (n % 2 == 0);
    }
};

void problem8() {
    Integer n(30);
    cout << n.get() << ' ';
    n.set(50);
    cout << n.get() << ' ';

    Integer m("300");
    cout << n.get() << ' ';
    cout << n.isEven() << endl << endl;
}
