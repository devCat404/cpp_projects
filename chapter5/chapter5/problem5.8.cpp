#include <iostream>

using namespace std;

class MyIntStack_ {
private:
	int* p;
	int size;
	int top_idx;
public:
	MyIntStack_();
	MyIntStack_(int size);
	MyIntStack_(const MyIntStack_& s);
	~MyIntStack_();
	bool push(int n);
	bool pop(int& n);
};

MyIntStack_::MyIntStack_() : MyIntStack_(size = 10) {}

MyIntStack_::MyIntStack_(int size) {
	this->size = size;
	p = new int[size];
	top_idx = 0;
}

MyIntStack_::MyIntStack_(const MyIntStack_& s) {
	this->size = s.size;
	this->top_idx = s.top_idx;
	this->p = new int[s.size];
	for (int i = 0; i < s.top_idx; ++i) {
		this->p[i] = s.p[i];
	}
}

MyIntStack_::~MyIntStack_() {
	delete[] p;
}

bool MyIntStack_::push(int n) {
	if (top_idx < size) {
		p[top_idx] = n;
		top_idx++;
		return true;
	}
	else {
		return false;
	}
}

bool MyIntStack_::pop(int& n) {
	if (top_idx > 0) {
		n = p[top_idx - 1];
		p[top_idx - 1] = 0;
		top_idx--;
		return true;
	}
	else return false;
}

void problem8() {
	MyIntStack_ a(10);
	a.push(10);
	a.push(20);
	MyIntStack_ b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값: " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값: " << n << endl << endl;
}
