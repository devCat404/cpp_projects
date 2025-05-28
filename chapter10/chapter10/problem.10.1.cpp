#include <iostream>
#include <vector>     

using namespace std;

template <class T>
void biggest(T src[], int y) {
	int max;
	for (int i = 0; i < y; i++)
	{
		max = src[0];
		if (max < src[i])
			max = src[i];
	}
	cout << max << endl;
}

void problem1() {
	int x[] = { 1, 2, 3, 4, 5 };
	int y[] = { 3, 4, 5, 6, 7 };
	int z[] = { 5 ,6, 7, 8, 10 };

	biggest(x, 5);
	biggest(y, 5);
	biggest(z, 5);

	cout << endl;
}
