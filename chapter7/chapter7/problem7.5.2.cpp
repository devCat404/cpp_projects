#include <iostream>

using namespace std;

class Color {
private:
    int red, green, blue;
public:
    Color() { red = green = blue = 0; }
    Color(int r, int g, int b) { red = r, green = g, blue = b; }
    void setColor(int r, int g, int b) { red = r, green = g, blue = b; }
    void show() { cout << red << ' ' << green << ' ' << blue << endl; }
    friend bool operator==(Color& self, Color& other);
    friend Color operator+(Color& self, Color& other);
};

bool operator==(Color& self, Color& other) {
    if (self.red == other.red && self.blue == other.blue && self.green == other.green) {
        return true;
    }
    else return false;
}

Color operator+(Color& self, Color& other) {
    Color temp;
    temp.red = self.red + other.red;
    temp.blue = self.blue + other.blue;
    temp.green = self.green + other.green;
    return temp;
}

void problem5_2() {
    Color red(255, 0, 0), blue(0, 0, 255), c;
    c = red + blue;
    c.show();

    Color fuchsia(255, 0, 255);
    if (c == fuchsia)
        cout << "보라색 맞음" << endl << endl;
    else
        cout << "보라색 아님" << endl << endl;
}
