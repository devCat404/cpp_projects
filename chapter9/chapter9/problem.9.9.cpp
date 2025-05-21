#include<iostream>
using namespace std;

class Printer {
private:
    string model;
    string manufacturer;
    int printCount;
    int availableCount;
public:
    Printer(string model, string manufacturer, int printCount, int availableCount) {
        this->model = model;
        this->manufacturer = manufacturer;
        this->printCount = printCount;
        this->availableCount = availableCount;
    }
    string getModel() { return model; }
    string getManufacturer() { return manufacturer; }
    void setPrintCount() { printCount++; }
    int getPrintCount() { return printCount; }
    void setAvailableCount(int pages) { availableCount -= pages; }
    int getAvailableCount() { return availableCount; }
    virtual void print(int pages) = 0;
    virtual void show() = 0;
};

class InkJetPrinter :public Printer {
    int availableInk;
public:
    InkJetPrinter(string model, string manufacturer, int printCount, int availableCount, int availableInk) :Printer(model, manufacturer, printCount, availableCount) {
        this->availableInk = availableInk;
    }
    int getAvailableInk() { return availableInk; }
    void show() {
        cout << getModel() << " ," << getManufacturer() << " ,남은 종이 " << getAvailableCount() << "장 ,남은 잉크 " << getAvailableInk() << endl;
    }
    void print(int pages) {
        if (getAvailableCount() - pages > 0 && getAvailableInk() - pages > 0) {
            cout << "프린트하였습니다." << endl;
            setPrintCount();
            setAvailableCount(pages);
            availableInk -= pages;
        }
        else {
            if (getAvailableCount() - pages < 0) {
                cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
            }
            else {
                cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
            }
        }

    }
};

class LaserPrinter :public Printer {
    int  availableToner;
public:
    LaserPrinter(string model, string manufacturer, int printCount, int availableCount, int availableToner) :Printer(model, manufacturer, printCount, availableCount) {
        this->availableToner = availableToner;
    }
    int getAvailableToner() { return availableToner; }
    void show() {
        cout << getModel() << " ," << getManufacturer() << " ,남은 종이 " << getAvailableCount() << "장 ,남은 토너 " << getAvailableToner() << endl;
    }
    void setAvailableToner(int pages) {
        availableToner -= pages;
    }

    void print(int pages) {
        if (getAvailableCount() - pages > 0 && getAvailableToner() - pages > 0) {

            setPrintCount();
            setAvailableCount(pages);
            setAvailableToner(pages);
            cout << "프린트하였습니다." << endl;
        }
        else {
            if (getAvailableCount() - pages < 0) {
                cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
            }
            else {
                cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
            }
        }
    }
};

void problem9() {
    InkJetPrinter ink("Officejet V40", "HP", 0, 5, 10);
    LaserPrinter laser("SCX-6x45", "삼성전자", 0, 3, 20);
    cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
    cout << "잉크젯 :";
    ink.show();
    cout << "레이저 :";
    laser.show();
    cout << endl;

    bool result = true;
    while (result) {
        int num;
        int page;
        string answer;
        cout << "프린터(1:잉크젯,2:레이저)와 매수 입력>>";
        cin >> num >> page;
        if (num == 1) {
            ink.print(page);
            ink.show();
            laser.show();
        }

        else if (num == 2) {
            laser.print(page);
            ink.show();
            laser.show();
        }
        cout << "계속 프린트 하시겠습니까(y/n)>>";
        cin >> answer;
        if (answer == "y") {
            result = true;

        }
        else {
            result = false;
        }
        cout << endl;
    }
}