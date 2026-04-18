#include <iostream>
#include <cstdlib>
#include <ctime>
#include "number_guessing.h"
using namespace std;

int main() {
    srand(time(0));

    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Number Guessing Game" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;

    do 
    {
        cout << "Enter your Guess: " << endl;
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
        cout << "Too low! Try again." << endl;
        }else if (guess > secretNumber) {
        cout <<"Too High! Try again." << endl;
         } else {
        cout << "Congratulation! You guessed the number " << secretNumber << " correctly!\n";
        cout << "It took you " << attempts << " guesses." << endl; 
         }
    } while (guess != secretNumber);
    return 0;
}