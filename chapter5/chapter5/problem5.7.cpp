#include <iostream>

using namespace std;

class MyIntStack {
private:
	int p[10];
	int top_idx;
public:
	MyIntStack();
	bool push(int n);
	bool pop(int& n);
};

MyIntStack::MyIntStack() {
	top_idx = 0;
}

bool MyIntStack::push(int n) {
	if (top_idx < 10) {
		p[top_idx] = n;
		top_idx++;
		return true;
	}
	else {
		return false;
	}
}

bool MyIntStack::pop(int& n) {
	if (top_idx > 0) {
		n = p[top_idx-1];
		p[top_idx-1] = 0;
		top_idx--;
		return true;
	}
	else return false;
}

void problem7() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) {
			cout << i << " ";
		}
		else {
			cout << endl << i + 1 << " 번째 stack full" << endl;
		}
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) {
			cout << n << ' ';
		}
		else {
			cout << endl << i + 1 << " 번째 stack empty";
		}
	}
	cout << endl << endl;
}
