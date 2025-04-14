#include <iostream>
#include <ctime>

using namespace std;

class Random {
public:
	static void seed() { srand((unsigned)time(0)); }
	static int nextInt(int min = 0, int max = RAND_MAX);
	static char nextAlphabet();
	static double nextDouble();
};

int Random::nextInt(int min, int max) {
	return min + rand() % (max - min + 1);
}

char Random::nextAlphabet() {
	int random_idx = rand() % 52;
	if (random_idx < 26) {
		return 'A' + random_idx;
	}
	else {
		return 'a' + (random_idx - 26);
	}
}

double Random::nextDouble() {
	return (double)rand() / (RAND_MAX + 1);
}

void problem7() {
	int lower = 1;
	int upper = 100;

	cout << lower << "에서 " << upper << "까지 랜덤한 정수 10개를 출력합니다." << endl;
	for (int i = 0; i < 10; i++) {
		int random = Random::nextInt(lower, upper);
		cout << random << ' ';
	}
	cout << endl << endl;

	cout << "알파벳을 랜덤하게  10개를 출력합니다." << endl;
	for (int i = 0; i < 10; i++) {
		char randAlpha = Random::nextAlphabet();
		cout << randAlpha << ' ';
	}
	cout << endl << endl;

	cout << "랜덤한 실수를 10개 출력합니다." << endl;
	for (int i = 0; i < 10; i++) {
		double randDouble = Random::nextDouble();
		cout << randDouble << ' ';
	}
	cout << endl << endl;
}
