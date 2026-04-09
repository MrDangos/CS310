// Author: Hugo Ramirez
// Date: 04/09/2025
// Description: game that asks the user to guess a random number between 1 and 10, with three attempts
#include <iostream>
using namespace std;

int main() {

    // Get random number each time program runs
    srand(time(0));

    // Declare variables
    int guess=0, i=3, randomNum=rand() % 10 + 1;


        while (i <= 1{
            // Get user input
            cout << "\nPick a number 1-10\n";
            cout << "Guess left: " << i << endl;
            cin >> guess;

            // Decides if the game is over
            if (guess == randomNum){
                cout << "\nYou win!\n" << guess << " is the correct number.\n";
                break;
            } else if (i == 1){
                cout << "\nYou lose!\n" << randomNum << " is the correct number.\n";
                break;
            };
            
            // Gives player a hint
            if (guess < randomNum){
                cout << "\nToo low, try again.\n";
            }
            else if (guess > randomNum){
                cout << "\nToo high, try again.\n";
            }
            i++;
        };


    return 0;
}