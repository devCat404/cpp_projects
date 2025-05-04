#include <iostream>

using namespace std;

class Book3 {
private:
	string title;
	int price, pages;
public:
	Book3(string title = "", int price = 0, int pages = 5) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}

	void show() {
		cout << title << " " << price << "원 " << pages << "페이지 " << endl;
	}

	string getTitle() { return title; }

	friend Book3 operator += (Book3 & book, int inc_price);
	friend Book3 operator -= (Book3 & book, int dec_price);
};

Book3 operator += (Book3 & book, int inc_price) {
	book.price += inc_price;
	return book;
}

Book3 operator -= (Book3 & book, int dec_price) {
	book.price -= dec_price;
	return book;
}

void problem1_2() {

	Book3 a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
	cout << endl;
}