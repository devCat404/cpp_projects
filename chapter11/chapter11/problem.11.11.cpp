#include <iostream>
                
using namespace std;

istream& pos(istream& stream) {
    cout << "��ġ��? >> ";
    return stream;
}

void problem11() {
    int x, y;
    cin >> pos >> x;
    cin >> pos >> y;
    cout << x << ',' << y << endl << endl;
}
