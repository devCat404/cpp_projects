#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Board {
private:
	static int cnt;
	static char board[10][100];
public:
	static void add(const char* announcement);
	static void print();
};

int Board::cnt = 0;
char Board::board[10][100];

void Board::add(const char* announcement) {
	strcpy(board[cnt], announcement);
	cnt++;
}

void Board::print() {
	cout << "**********" << "�Խ��� �Դϴ�." << "**********" << endl;
	for (int i = 0; i < cnt; i++) {
		cout << i << ": " << board[i] << endl;
	}
	cout << endl;
}

void problem9() {
	Board::add("�߰��һ�� �������� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿����ּ���.");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���.");
	Board::print();
}
