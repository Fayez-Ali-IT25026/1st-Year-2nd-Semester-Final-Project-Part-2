#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int playerPosition = 1;
int enemyPosition = 1;

// Function to display the game
void displayGame() {

    cout << "================================\n";
    cout << "        CAR RACING GAME\n";
    cout << "================================\n\n";

    cout << "        |       |\n";

    // Enemy car
    if (enemyPosition == 0) {
        cout << "     🚙  |       |\n";
    }
    else if (enemyPosition == 1) {
        cout << "        |   🚙  |\n";
    }
    else {
        cout << "        |       |  🚙\n";
    }

    cout << "        |       |\n";

    // Player car
    if (playerPosition == 0) {
        cout << "     🚗  |       |\n";
    }
    else if (playerPosition == 1) {
        cout << "        |   🚗  |\n";
    }
    else {
        cout << "        |       |  🚗\n";
    }

    cout << "        |_______|\n\n";

    cout << "Score: 0\n";
    cout << "Lives: 3\n";
}

// Generate a random enemy position
void generateEnemy() {

    enemyPosition = rand() % 3;
}

int main() {

    // Initialize random number generator
    srand(time(0));

    char move;

    while (true) {

        generateEnemy();

        displayGame();

        cout << "\nA = Left | D = Right | Q = Quit\n";
        cout << "Enter your move: ";
        cin >> move;

        if (move == 'a' || move == 'A') {

            if (playerPosition > 0) {
                playerPosition--;
            }
        }
        else if (move == 'd' || move == 'D') {

            if (playerPosition < 2) {
                playerPosition++;
            }
        }
        else if (move == 'q' || move == 'Q') {

            cout << "\nGame Over!\n";
            break;
        }
        else {

            cout << "\nInvalid input!\n";
        }
    }

    return 0;
}