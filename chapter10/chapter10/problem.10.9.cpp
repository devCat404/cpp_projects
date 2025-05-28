#include <iostream>
#include <vector>
                
using namespace std;

void problem9() {
	vector<int> v;
	int num;
	double sum{};
	while (true)
	{
		cout << "정수를 입력하세요(0을 입력하면 종료) >> ";
		cin >> num;
		if (num == 0)
			return;
		v.push_back(num);

		for (int i = 0; i < size(v); i++) {
			cout << v[i] << " ";
			sum += v[i];
		}
		cout << endl;
		double regular = sum / size(v);
		cout << "평균 = " << regular << endl;
		sum = 0;
	}
	cout << endl;
}
