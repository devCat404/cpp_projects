#include <iostream>
using namespace std;

class Book4 {
private:
	string title;
	int price, pages;
public:
	Book4(string title = "", int price = 0, int pages = 5) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}

	void show() {
		cout << title << " " << price << "원 " << pages << "페이지 " << endl;
	}

	string getTitle() { return title; }
	
	bool operator==(int comp_price);
	bool operator==(string comp_title);
	bool operator==(Book4& comp_book);
};

bool Book4::operator==(int comp_price) {
	if (price == comp_price) {
		return true;
	}
	else return false;
}

bool Book4::operator==(string comp_title) {
	if (title == comp_title) {
		return true;
	}
	else return false;
}

bool Book4::operator==(Book4& comp_book) {
	if (this->price == comp_book.price && this->title == comp_book.title) {
		return true;
	}
	else return false;
}

void problem2() {

	Book4 a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000) cout << "정가 30000원" << endl;
	if (a == "명품 C++") cout << "명품 C++ 입니다." << endl;
	if (a == b) cout << "두책이 같은 책입니다." << endl << endl;
	cout << endl;
}
