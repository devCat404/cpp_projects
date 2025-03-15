#include "Box.h"
        
#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++) 

using namespace std;

//구현부(Box.cpp)

Box::Box(int w, int h) { setSize(w, h); fill = '*'; };
void Box::setFill(char f) { fill = f; };
void Box::setSize(int w, int h) { width = w; height = h; };
void Box::draw() {
    loop(i, 0, height) {
        loop(j, 0, width) {
            print(fill);
        }
        print('\n');
    }
}

//실현부(main.cpp)

void problem11() {
    Box b(10, 2);
    b.draw();
    cout << endl;
    b.setSize(7, 4);
    b.setFill('^');
    b.draw();
}
