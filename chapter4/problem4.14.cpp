#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Player {
private:
    string players;
public:
    void setName(string name) { players = name; }
    string getName() { return players; }
};

class GamblingGame {
private:
    Player player[2];
public:
    bool gameLogic();
    void gameStart();
    ~GamblingGame();
};

bool GamblingGame::gameLogic() {

    srand((unsigned)time(0));

    for (int i = 0; i < 2; i++) {
        cout << player[i].getName() << ": <Enter>";
        cin.get(); 

        int slot[3];
        for (int j = 0; j < 3; j++) {
            slot[j] = rand() % 3;  
            cout << '\t' << slot[j] << "\t";
        }
        cout << "\t";

        if (slot[0] == slot[1] && slot[1] == slot[2]) {
            cout << player[i].getName() << "님 승리!!" << endl;
            return true; 
        }
        else {
            cout << "아쉽군요!" << endl << endl;
        }
    }
    return false; 
}

void GamblingGame::gameStart() {

    getchar();

    string name1, name2;
    cout << "*****  갬블링 게임을 시작합니다. *****\n";
    cout << "첫번째 선수 이름: ";
    getline(cin, name1, '\n');
    cout << "두번째 선수 이름: ";
    getline(cin, name2, '\n');

    player[0].setName(name1);
    player[1].setName(name2);
    
    while (true) {
        if (gameLogic()) {
            break;
        }
    }
}

GamblingGame::~GamblingGame() {
    cout << "***** 게임 종료. *****\n\n";
}

void problem14() {

    GamblingGame G;
    G.gameStart();
}
