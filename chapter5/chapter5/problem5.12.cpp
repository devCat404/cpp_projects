#include <iostream>

using namespace std;

void problem12_4();

class Dept {
private:
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	Dept(const Dept& dept);
	~Dept();
	int getSize() { return size; }
	void read();
	bool isOver60(int index);
};

Dept::Dept(const Dept& dept) {
	this->size = dept.size;
	this->scores = new int[this->size];
	for (int i = 0; i < this->size; i++) {
		this->scores[i] = dept.scores[i];
	}
}

Dept::~Dept() {
	delete[] scores;
}

void Dept::read() {
	cout << "10개 점수 입력: ";
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
}

bool Dept::isOver60(int index) {
	if (scores[index] >= 60) {
		return true;
	}
	else {
		return false;
	}
}

int countPass(Dept dept) {
	int cnt = 0; 
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) {
			cnt++;
		}
	}
	return cnt;
}

void problem12() {
	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명" << endl << endl;

	problem12_4();
}
