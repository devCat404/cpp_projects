#include <iostream>
#include <string>
#include <vector>
                
using namespace std;

class Book {
protected:
	string name;
	int year;
	string writer;
public:
	Book(int year, string name, string writer)
	{
		this->year = year;
		this->name = name;
		this->writer = writer;
	}
	string getName()
	{
		return name;
	}
	string getWriter()
	{
		return writer;
	}
	int getYear()
	{
		return year;
	}
};

void problem11() {
	vector<Book> bv;
	string name;
	string writer;
	int year;
	cout << "�԰��� å�� �Է��ϼ���. �⵵�� -1�� �Է��ϸ� �����մϴ�. " << endl;
	while (true)
	{
		cout << "�⵵ >> ";
		cin >> year;
		if (year == -1) {
			cout << "�� �԰�� å�� " << size(bv) << "�Դϴ�. " << endl;
			break;
		}
		cin.ignore();
		cout << "å �̸� >> ";
		getline(cin, name);

		cout << "���� >> ";
		getline(cin, writer);

		Book book(year, name, writer);
		bv.push_back(book);
	}
	cin.ignore();
	cout << "�˻��ϰ��� �ϴ� å�� ���� �̸��� �Է��ϼ��� >> ";
	getline(cin, writer);
	for (int i = 0; i < size(bv); i++)
	{
		if (bv[i].getWriter() == writer)
			cout << bv[i].getYear() << ", " << bv[i].getName() << ", " << bv[i].getWriter() << endl;
	}
	cout << "�˻��ϰ��� �ϴ� å�� �Ⱓ ������ �Է��ϼ��� >> ";
	cin >> year;
	for (int i = 0; i < size(bv); i++)
	{
		if (bv[i].getYear() == year)
			cout << bv[i].getYear() << ", " << bv[i].getName() << ", " << bv[i].getWriter() << endl;
	}
	cout << endl;
}
