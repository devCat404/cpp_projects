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
        cout << getModel() << " ," << getManufacturer() << " ,���� ���� " << getAvailableCount() << "�� ,���� ��ũ " << getAvailableInk() << endl;
    }
    void print(int pages) {
        if (getAvailableCount() - pages > 0 && getAvailableInk() - pages > 0) {
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
            setPrintCount();
            setAvailableCount(pages);
            availableInk -= pages;
        }
        else {
            if (getAvailableCount() - pages < 0) {
                cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
            }
            else {
                cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
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
        cout << getModel() << " ," << getManufacturer() << " ,���� ���� " << getAvailableCount() << "�� ,���� ��� " << getAvailableToner() << endl;
    }
    void setAvailableToner(int pages) {
        availableToner -= pages;
    }

    void print(int pages) {
        if (getAvailableCount() - pages > 0 && getAvailableToner() - pages > 0) {

            setPrintCount();
            setAvailableCount(pages);
            setAvailableToner(pages);
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
        }
        else {
            if (getAvailableCount() - pages < 0) {
                cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
            }
            else {
                cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
            }
        }
    }
};

void problem9() {
    InkJetPrinter ink("Officejet V40", "HP", 0, 5, 10);
    LaserPrinter laser("SCX-6x45", "�Ｚ����", 0, 3, 20);
    cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����." << endl;
    cout << "��ũ�� :";
    ink.show();
    cout << "������ :";
    laser.show();
    cout << endl;

    bool result = true;
    while (result) {
        int num;
        int page;
        string answer;
        cout << "������(1:��ũ��,2:������)�� �ż� �Է�>>";
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
        cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
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