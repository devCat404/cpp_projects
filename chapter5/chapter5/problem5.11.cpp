#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class Book {
private:
	char* title;
	int price;
public:
	Book(const char* title, int price);
	Book(const Book& book);
	~Book();
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const char* title, int price) {
	int length = strlen(title);
	this->title = new char[length + 1];
	strcpy(this->title, title);
	this->price = price;
}

Book::Book(const Book& book) {
	int length = strlen(book.title);
	this->title = new char[length + 1];
	strcpy(this->title, book.title);
	this->price = book.price;
}

Book::~Book() {
	if (this->title) {
		delete[] title;
	}
}

void Book::set(const char* title, int price) {
	if (this->title) {
		delete[] this->title;
	}
	int length = strlen(title);
	this->title = new char[length + 1];
	strcpy(this->title, title);
	this->price = price;
}

class TextBook {
private:
	string title;
	int price;
public:
	TextBook(string title, int price) { this->title = title, this->price = price; }
	void set(string title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

void TextBook::set(string title, int price) {
	this->title = title;
	this->price = price;
}

void problem11() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
	cout << endl;

	cout << "******************" << "< string을 이용해서 다시 >" << "********************" << endl << endl;

	TextBook cpp2("명품C++", 10000);
	TextBook java2 = cpp2;
	java2.set("명품자바", 12000);
	cpp2.show();
	java2.show();
	cout << endl;
}
