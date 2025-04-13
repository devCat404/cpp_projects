#include <iostream>

using namespace std;

class Department {
private:
	int size;
	int* scores;
public:
	Department(int size) {
		this->size = size;
		scores = new int[size];
	}
	~Department();
	int rtnSize() const { return size; }
	void input_scores();
	bool checkOver60(int index) const;
};

Department::~Department() {
	delete[] scores;
}

void Department::input_scores() {
	cout << "10개 점수 입력: ";
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
}

bool Department::checkOver60(int index) const {
	if (scores[index] >= 60) {
		return true;
	}
	else {
		return false;
	}
}

int countPass(const Department& a) {
	int cnt = 0;
	for (int i = 0; i < a.rtnSize(); i++) {
		if (a.checkOver60(i)) {
			cnt++;
		}
	}
	return cnt;
}

void problem12_4() {
	Department com(10);
	com.input_scores();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명" << endl << endl;
}
