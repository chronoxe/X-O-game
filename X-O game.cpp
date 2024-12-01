#include <iostream>
#include <cstdlib>
using namespace std;

bool gameover = false;
char usersquare[]={ '1', '2', '3', '4', '5', '6', '7', '8', '9' };  
char userchoseside;
char systemchoise;

void draw() {
    cout << " _____ _____ _____ " << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << usersquare[0] << "  |  " << usersquare[1] << "  |  " << usersquare[2] << "  |  " << endl;
    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << usersquare[3] << "  |  " << usersquare[4] << "  |  " << usersquare[5] << "  |  " << endl;
    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << usersquare[6] << "  |  " << usersquare[7] << "  |  " << usersquare[8] << "  |  " << endl;
    cout << "|_____|_____|_____|" << endl;
}

void logic() {
    if ((usersquare[0] == usersquare[1] && usersquare[1] == usersquare[2]) ||
        (usersquare[3] == usersquare[4] && usersquare[4] == usersquare[5]) ||
        (usersquare[6] == usersquare[7] && usersquare[7] == usersquare[8]) ||
        (usersquare[0] == usersquare[3] && usersquare[3] == usersquare[6]) ||
        (usersquare[1] == usersquare[4] && usersquare[4] == usersquare[7]) ||
        (usersquare[2] == usersquare[5] && usersquare[5] == usersquare[8]) ||
        (usersquare[0] == usersquare[4] && usersquare[4] == usersquare[8]) ||
        (usersquare[2] == usersquare[4] && usersquare[4] == usersquare[6])) {
        gameover = true;
    }
}

void inputuseronly() {
    int userInput;
    bool validInput = false;

    while (!validInput) {
        cout << "Which number you want to fill in (1-9): ";
        cin >> userInput;

        if (userInput >= 1 && userInput <= 9 && usersquare[userInput - 1] != 'X' && usersquare[userInput - 1] != 'O') {
            usersquare[userInput - 1] = userchoseside;
            validInput = true;
        }
        else {
            cout << "Invalid move, try again." << endl;
        }
    }
}

void inputsystemonly() {
    srand(time(0));
    int randomIndex = rand() % 9;

    while (usersquare[randomIndex] == 'X' || usersquare[randomIndex] == 'O') {
        randomIndex = rand() % 9;
    }
    usersquare[randomIndex] = systemchoise;
}

int main() {
    cout << "Choose your side (X or O): ";
    cin >> userchoseside;
    userchoseside = toupper(userchoseside);
    systemchoise = (userchoseside == 'X') ? 'O' : 'X';

    cout << "Choose who starts (user or system): ";
    char playstarter;
    cin >> playstarter;
    playstarter = tolower(playstarter);

    draw();

    while (!gameover) {
        if (playstarter == 'u') {
            draw();
            inputuseronly();
            logic();
            if (gameover) {
                cout << "Game has ended. User wins!" << endl;
                break;
            }
            inputsystemonly();
            logic();
            system("clear");
            if (gameover) {
                cout << "Game has ended. System wins!" << endl;
                break;
            }
        }
        else if (playstarter == 's') {
            inputsystemonly();
            draw();
            logic();
            if (gameover) {
                cout << "Game has ended. System wins!" << endl;
                break;
            }
            inputuseronly();
            draw();
            logic();
            if (gameover) {
                cout << "Game has ended. User wins!" << endl;
                break;
            }
        }
    }
    return 0;
}
