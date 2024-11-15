#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>

using namespace std;

int main() {
    srand(time(0));

    string difficulty;
    int maxNumber, guessesAllowed;

    cout << "Choose difficulty (easy, medium, hard): ";
    cin >> difficulty;

    if (difficulty == "easy") {
        maxNumber = 50;
        guessesAllowed = 10;
    } else if (difficulty == "medium") {
        maxNumber = 100;
        guessesAllowed = 7;
    } else if (difficulty == "hard") {
        maxNumber = 200;
        guessesAllowed = 5;
    } else {
        cout << "Invalid difficulty level." << endl;
        return 1; // Indicate an error
    }

    int secretNumber = rand() % maxNumber + 1;
    int guessesLeft = guessesAllowed;
    int guess;

    cout << "Welcome to the Number Guessing Game (" << difficulty << " mode)!" << endl;
    cout << "I'm thinking of a number between 1 and " << maxNumber << "." << endl;

    while (guessesLeft > 0) {
        cout << "\nYou have " << guessesLeft << " guesses left." << endl;
        cout << "Take a guess: ";
        cin >> guess;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (guess < secretNumber) {
            cout << "Too low!" << endl;
        } else if (guess > secretNumber) {
            cout << "Too high!" << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << guessesAllowed - guessesLeft << " tries." << endl;
            return 0;
        }
        guessesLeft--;
    }

    cout << "\nYou ran out of guesses. The number was " << secretNumber << "." << endl;
    return 0;
}
