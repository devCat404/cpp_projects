#include <iostream>

using namespace std;

class Book5 {
private:
	string title;
	int price, pages;
public:
	Book5(string title = "", int price = 0, int pages = 5) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}

	void show() {
		cout << title << " " << price << "�� " << pages << "������ " << endl;
	}

	string getTitle() { return title; }

	bool operator! () {
		if (price == 0) {
			return true;
		}
		else return false;
	}
};

void problem3() {
	Book5 book("�������", 0, 50);
	if (!book) cout << "��¥��" << endl << endl;
}
