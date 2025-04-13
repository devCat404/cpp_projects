#include <iostream>

using namespace std;

class Buffer {
private:
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += next; }
	void print() { cout << text << endl; }
};

Buffer& append(Buffer& s, string str) {
	s.add(str);
	return s;
}

void problem10() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys");
	temp.print();
	buf.print();
	cout << endl;
}
