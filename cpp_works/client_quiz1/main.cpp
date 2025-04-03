#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Clients {
    int id;
    string name;
    string address;
    string tel;
    string gender;

public:
    Clients();
    void insertClient(int newId, string newName, string newTel, string newAddress, string newGender);
    void displayClient();
    void listClient();
    int getId(); 
};

Clients::Clients() {}

void Clients::insertClient(int newId, string newName, string newTel, string newAddress, string newGender) {
    id = newId;
    name = newName;
    tel = newTel;
    address = newAddress;
    gender = newGender;
}

void Clients::displayClient() {
    cout << "Client ID: " << id
        << ", Name: " << name
        << ", Gender: " << gender
        << ", Tel: " << tel
        << ", Address: " << address << endl;
}

void Clients::listClient() {
    cout << "ID: " << id << ", Name: " << name << ", Gender: " << gender << endl;
}

int Clients::getId() {
    return id;
}

class Menus {
public:
    Menus();
    int display();
};

Menus::Menus() {}

int Menus::display() {
    int selection;
    cout << "\n------------ MENU ------------\n";
    cout << "1. insert clients\n";
    cout << "2. delete clients\n";
    cout << "3. display clients\n";
    cout << "4. list clients\n";
    cout << "5. reference\n";
    cout << "0. exit\n";
    cout << "------------------------------\n";
    cout << "Please input selection (0~5): ";
    cin >> selection;
    return selection;
}

int main() {
    vector<Clients> clientList;
    Menus menu;

    while (true) {
        int choice = menu.display();

        if (choice == 1) {
            int numOfClients;
            cout << "Input number of clients: ";
            cin >> numOfClients;
            getchar();

            for (int i = 0; i < numOfClients; i++) {
                Clients client;
                int id;
                string name, tel, address, gender;

                cout << "\n[Client #" << (i + 1) << "]\n";
                cout << "Input ID: ";
                cin >> id;
                getchar();
                cout << "Input Name: ";
                getline(cin, name, '\n');
                cout << "Input Gender (M/F): ";
                getline(cin, gender, '\n');
                cout << "Input Tel: ";
                getline(cin, tel);
                cout << "Input Address: ";
                getline(cin, address, '\n');

                client.insertClient(id, name, tel, address, gender);
                clientList.push_back(client);
            }

        }
        else if (choice == 2) {
            int delId;
            cout << "Enter the ID of client to delete: ";
            cin >> delId;

            bool found = false;
            for (auto it = clientList.begin(); it != clientList.end(); ++it) {
                if (it->getId() == delId) {
                    clientList.erase(it);
                    cout << "Client deleted.\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Client ID not found.\n";
            }

        }
        else if (choice == 3) {
            cout << "\n------ All Client Details ------\n";
            if (clientList.empty()) {
                cout << "No clients available.\n";
            }
            else {
                for (auto& client : clientList) {
                    client.displayClient();
                }
            }

        }
        else if (choice == 4) {
            cout << "\n------ Client List (Short) ------\n";
            if (clientList.empty()) {
                cout << "No clients available.\n";
            }
            else {
                for (auto& client : clientList) {
                    client.listClient();
                }
            }

        }
        else if (choice == 5) {
            cout << "\n[Reference] Hello world.\n" << endl;

        }
        else if (choice == 0) {
            cout << "Program exited.\n";
            break;
        }
        else {
            cout << "Invalid selection. Please try again.\n";
        }
    }

    return 0;
}
