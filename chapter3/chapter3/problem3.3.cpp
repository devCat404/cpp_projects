#include <iostream>
#include <string>
        
#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++) 

using namespace std;

class Account {
private:
    int id;
    int pulse = 0;
    string owner;

public:
    Account(string name, int n, int money) {
        owner = name;
        pulse += money;
        id = n;
    }

    void deposit(int plus) {
        pulse += plus;
    }

    int withdraw(int minus) {
        pulse -= minus;
        return minus;
    }

    int inquiry() {
        return pulse;
    }

    string getOwner() {
        return owner;
    }
};

void problem3() {
    Account a("kitae", 1, 5000);
    a.deposit(50000);
    cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << "¿ø" << endl;
    a.withdraw(20000);
    cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << "¿ø\n" << endl;
}
