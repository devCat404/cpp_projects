#include <iostream>
#include <string>
using namespace std;

class Seat {
    string name; 
public:
    Seat() { name = "---"; }
    bool reserve(string n) {
        if (name != "---") return false;
        name = n;
        return true;
    }
    bool cancel(string n) {
        if (name == n) {
            name = "---";
            return true;
        }
        return false;
    }
    string getName() { return name; }
    bool isEmpty() { return name == "---"; }
};

class Schedule {
    string time; 
    Seat seats[8];
public:
    Schedule(string time) : time(time) {}
    void show() {
        cout << time << "시: ";
        for (int i = 0; i < 8; ++i) {
            cout << seats[i].getName() << " ";
        }
        cout << endl;
    }
    void showSeatsOnly() {
        for (int i = 0; i < 8; ++i) {
            cout << seats[i].getName() << " ";
        }
        cout << endl;
    }
    bool reserve(int seatNumber, string name) {
        if (seatNumber < 1 || seatNumber > 8) return false;
        return seats[seatNumber - 1].reserve(name);
    }
    bool cancel(int seatNumber, string name) {
        if (seatNumber < 1 || seatNumber > 8) return false;
        return seats[seatNumber - 1].cancel(name);
    }
    string getTime() { return time; }
};

class AirlineBook {
    Schedule schedules[3] = { Schedule("07"), Schedule("12"), Schedule("17") };
public:
    void showAll() {
        for (int i = 0; i < 3; ++i) {
            schedules[i].show();
        }
    }
    void showSeatsLine(int idx) {
        if (idx >= 0 && idx < 3) {
            cout << schedules[idx].getTime() << "시: ";
            schedules[idx].showSeatsOnly();
        }
    }
    bool reserve(int idx, string name, int seatNumber) {
        if (idx < 0 || idx >= 3) return false;
        return schedules[idx].reserve(seatNumber, name);
    }
    bool cancel(int idx, string name, int seatNumber) {
        if (idx < 0 || idx >= 3) return false;
        return schedules[idx].cancel(seatNumber, name);
    }
};

class Console {
public:
    static void menu() {
        cout << "\n예약:1, 취소:2, 보기:3, 끝내기:4 >> ";
    }
    static int inputTimeIndex() {
        int t;
        cout << "07시: 1, 12시: 2, 17시: 3 >> ";
        cin >> t;
        return t - 1;
    }
    static string inputName() {
        string n;
        cout << "예약자 이름: ";
        cin >> n;
        return n;
    }
    static int inputSeat() {
        int s;
        cout << "좌석 번호(1~8): ";
        cin >> s;
        return s;
    }
};

void problem9() {
    AirlineBook book;
    cout << "***** 한성항공에 오신것을 환영합니다 *****" << endl;

    while (true) {
        Console::menu();
        int choice;
        cin >> choice;

        if (choice == 1) {
            int tIdx = Console::inputTimeIndex();
            book.showSeatsLine(tIdx);
            int seat = Console::inputSeat();
            string name = Console::inputName();
            if (!book.reserve(tIdx, name, seat)) cout << "예약 불가\n";
        }
        else if (choice == 2) {
            int tIdx = Console::inputTimeIndex();
            book.showSeatsLine(tIdx);
            int seat = Console::inputSeat();
            string name = Console::inputName();
            if (!book.cancel(tIdx, name, seat)) cout << "취소 불가\n";
        }
        else if (choice == 3) {
            book.showAll();
        }
        else if (choice == 4) {
            cout << "예약 시스템을 종료합니다.\n";
            break;
        }
        else {
            cout << "잘못된 입력입니다.\n";
        }
    }
    cout << endl;
}
