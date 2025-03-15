#pragma once

#include <iostream>

using namespace std;

class Add {
private:
	int a, b;

public:
	Add();
	void setValue(int x, int y);
	int calculate();
};

class Sub {
private:
	int a, b;

public:
	Sub();
	void setValue(int x, int y);
	int calculate();
};

class Mul {
private:
	int a, b;

public:
	Mul();
	void setValue(int x, int y);
	int calculate();
};

class Div {
private:
	int a, b;

public:
	Div();
	void setValue(int x, int y);
	int calculate();
};