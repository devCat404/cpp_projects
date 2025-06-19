#include <iostream>
#include <iomanip>
#include <cmath>
                
using namespace std;

void problem6() {
    cout.setf(ios::left);
    cout << setw(15) << "Number";
    cout << setw(15) << "Square";
    cout << setw(15) << "Square Root";
    cout << endl;
    for (int j = 0; j < 10; j++) {
        int num = 5 * j;
        int power = pow(num, 2);
        double square = sqrt(num);
        cout.fill('_');
        cout << setw(15) << num;
        cout.fill('_');
        cout << setw(15) << power;
        cout.fill('_');
        cout.precision(3);
        cout << setw(15) << square;
        cout << endl;
    }
    cout << endl;
}
