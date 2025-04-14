#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <vector>

using namespace std;

#include <iostream>
#include <cstring> 

using namespace std;

#define MAX_LOGS 100

struct Log {
    char tag[20];
    char logs[100];
};

class Trace {
private:
    static Log info[MAX_LOGS];
    static int cnt;
public:
    static void put(const char* tag, const char* debug_info);
    static void print(const char* tag = "");
};

Log Trace::info[MAX_LOGS];
int Trace::cnt = 0;

void Trace::put(const char* tag, const char* debug_info) {
    if (cnt < MAX_LOGS) {
        strcpy(info[cnt].tag, tag);
        strcpy(info[cnt].logs, debug_info);
        cnt++;
    }
}

void Trace::print(const char* tag) {
    if (strcmp(tag, "") == 0)
        cout << "----- 모든 Trace 정보를 출력합니다. -----" << endl;
    else
        cout << "----- " << tag << " 태그의 Trace 정보를 출력합니다. -----" << endl;

    for (int i = 0; i < cnt; i++) {
        if (strcmp(tag, "") == 0 || strcmp(tag, info[i].tag) == 0) {
            cout << "[" << info[i].tag << "] : " << info[i].logs << endl;
        }
    }
    cout << endl;
}


void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력: ";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl << endl;
}

void problem8() {
	Trace::put("main()", "프로그램 시작합니다.");
	f();
	Trace::put("main()", "종료.");

	Trace::print("f()");
	Trace::print();

	cout << endl;
}
