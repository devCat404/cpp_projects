#include <iostream>

using namespace std;

class Accumulator {
private:
	int value;
public:
	Accumulator(int value);
	Accumulator& add(int n);
	int get();
};

Accumulator::Accumulator(int value) {
	this->value = value;
}

Accumulator& Accumulator::add(int n) {
	value += n;
	return *this;
}

int Accumulator::get() {
	return value;
}

void problem9() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get() << endl << endl;
}
