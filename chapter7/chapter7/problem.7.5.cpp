#include <iostream>

using namespace std;

void problem5_2();

class Color {
private:
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r, green = g, blue = b; }
	void setColor(int r, int g, int b) { red = r, green = g, blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
    Color operator+(Color& other) {
        Color new_one;
        new_one.red = this->red + other.red;
        new_one.blue = this->blue + other.blue;
        new_one.green = this->green + other.green;
        return new_one;
    }
    bool operator==(Color& other) {
        if (this->red == other.red && this->blue == other.blue && this->green == other.green) {
            return true;
        }
        else return false;
    }
};

void problem5() {
    Color red(255, 0, 0), blue(0, 0, 255), c;
    c = red + blue;
    c.show();

    Color fuchsia(255, 0, 255);
    if (c == fuchsia)
        cout << "보라색 맞음" << endl << endl;
    else
        cout << "보라색 아님" << endl << endl;
    problem5_2();
}
