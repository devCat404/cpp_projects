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
	cout << "**********" << "게시판 입니다." << "**********" << endl;
	for (int i = 0; i < cnt; i++) {
		cout << i << ": " << board[i] << endl;
	}
	cout << endl;
}

void problem9() {
	Board::add("중간소사는 감독없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요.");
	Board::print();
}
