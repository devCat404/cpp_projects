#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
        
#define print(x) cout << x
#define loop(i, a, b) for(int i = a; i < b; i++) 

using namespace std;

class Date {
private:
    int year, month, day;
    string ymd;

public:
    Date(int y, int m, int d) {
        year = y; month = m; day = d;
    }

    Date(string ymd) {  
        sscanf(ymd.c_str(), "%d/%d/%d", &year, &month, &day);
    }

    int getYear() {
        return year;
    }

    int getMonth() {
        return month;
    }

    int getDay() {
        return day;
    }

    void show() {
        printf("%d³â %d¿ù %dÀÏ\n", year, month, day);
    }
};

void problem2() {
    Date birth(2014, 3, 20);
    Date independenceDay("1945/8/15");

    independenceDay.show();
    cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl << endl;
}
