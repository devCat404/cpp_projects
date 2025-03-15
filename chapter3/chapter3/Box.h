#pragma once

#include <iostream>

using namespace std;

class Box {
private:
	int width, height;
	char fill;

public:
	Box(int w, int h);
	void setFill(char f);
	void setSize(int w, int h);
	void draw();
};

