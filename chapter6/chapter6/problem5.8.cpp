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
        cout << "----- ��� Trace ������ ����մϴ�. -----" << endl;
    else
        cout << "----- " << tag << " �±��� Trace ������ ����մϴ�. -----" << endl;

    for (int i = 0; i < cnt; i++) {
        if (strcmp(tag, "") == 0 || strcmp(tag, info[i].tag) == 0) {
            cout << "[" << info[i].tag << "] : " << info[i].logs << endl;
        }
    }
    cout << endl;
}


void f() {
	int a, b, c;
	cout << "�� ���� ������ �Է�: ";
	cin >> a >> b;
	Trace::put("f()", "������ �Է¹޾���");
	c = a + b;
	Trace::put("f()", "�� ���");
	cout << "���� " << c << endl << endl;
}

void problem8() {
	Trace::put("main()", "���α׷� �����մϴ�.");
	f();
	Trace::put("main()", "����.");

	Trace::print("f()");
	Trace::print();

	cout << endl;
}
