#include <iostream>

using namespace std;

void problem1_2();

class Book {
private:
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 5) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}

	void show() {
		cout << title << " " << price << "�� " << pages << "������ " << endl;
	}

	string getTitle() { return title; }

	Book operator+=(int inc_price) {
		this->price += inc_price;
		return *this;
	}
	Book operator-=(int dec_price) {
		this->price -= dec_price;
		return *this;
	}
};

void problem1() {

	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
	cout << endl;
	problem1_2();
}