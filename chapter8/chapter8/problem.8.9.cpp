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
        cout << time << "��: ";
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
            cout << schedules[idx].getTime() << "��: ";
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
        cout << "\n����:1, ���:2, ����:3, ������:4 >> ";
    }
    static int inputTimeIndex() {
        int t;
        cout << "07��: 1, 12��: 2, 17��: 3 >> ";
        cin >> t;
        return t - 1;
    }
    static string inputName() {
        string n;
        cout << "������ �̸�: ";
        cin >> n;
        return n;
    }
    static int inputSeat() {
        int s;
        cout << "�¼� ��ȣ(1~8): ";
        cin >> s;
        return s;
    }
};

void problem9() {
    AirlineBook book;
    cout << "***** �Ѽ��װ��� ���Ű��� ȯ���մϴ� *****" << endl;

    while (true) {
        Console::menu();
        int choice;
        cin >> choice;

        if (choice == 1) {
            int tIdx = Console::inputTimeIndex();
            book.showSeatsLine(tIdx);
            int seat = Console::inputSeat();
            string name = Console::inputName();
            if (!book.reserve(tIdx, name, seat)) cout << "���� �Ұ�\n";
        }
        else if (choice == 2) {
            int tIdx = Console::inputTimeIndex();
            book.showSeatsLine(tIdx);
            int seat = Console::inputSeat();
            string name = Console::inputName();
            if (!book.cancel(tIdx, name, seat)) cout << "��� �Ұ�\n";
        }
        else if (choice == 3) {
            book.showAll();
        }
        else if (choice == 4) {
            cout << "���� �ý����� �����մϴ�.\n";
            break;
        }
        else {
            cout << "�߸��� �Է��Դϴ�.\n";
        }
    }
    cout << endl;
}
