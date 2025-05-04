#include <iostream>
#include <string>

using namespace std;

class Book6 {
private:
	string title;
	int price, pages;
public:
	Book6(string title = "", int price = 0, int pages = 5) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}

	void show() {
		cout << title << " " << price << "원 " << pages << "페이지 " << endl;
	}

	string getTitle() { return title; }

	friend bool operator< (string comp_title, Book6& book);
};

bool operator<(string comp_title, Book6& book) {
	if (comp_title < book.title) {
		return true;
	}
	else return false;
}

void problem4() {
	getchar();
	Book6 a("청춘", 2000, 300);
	string b;
	cout << "책 이름을 입력하세요>> ";
	getline(cin, b); 
	if (b < a)
		cout << '"' << a.getTitle() << '"' << "이 " << '"' << b << '"' << "보다 뒤에 있구나!" << endl << endl;
}
