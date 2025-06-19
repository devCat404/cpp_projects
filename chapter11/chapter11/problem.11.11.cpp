#include <iostream>
                
using namespace std;

istream& pos(istream& stream) {
    cout << "À§Ä¡´Â? >> ";
    return stream;
}

void problem11() {
    int x, y;
    cin >> pos >> x;
    cin >> pos >> y;
    cout << x << ',' << y << endl << endl;
}
