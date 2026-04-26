/*
 * Student Name: Daniel Preller
 * File Name: Week6.cpp
 * Date: 4/20/2026
*/

#include <conio.h>
#include <iostream>

using namespace std;

int main() {
    enum setting {// Enum for representing the speed settings of a fan
        OFF, //<-- added the missing comas to separate the enum values
        LOW,
        MEDIUM,
        HIGH //<-- added HIGH to the enum to represent the high speed setting
    };

    int userSelection = 0;

    cout << "\n\n";

    while (true) {// Executes until the user enters a number out of range
        switch (static_cast<setting>(userSelection)) {// Prints the current speed based on the user input
            case OFF:
                cout << "  The fan is currently off." << endl;
                break;
            case LOW:
                cout << "  The fan speed is currently set to low." << endl;
                break; //<-- added break to prevent fall-through to the next case
            case MEDIUM:
                cout << "  The fan speed is currently set to medium." << endl;
                break;
            case HIGH:
                cout << "  The fan speed is currently set to high." << endl;
                break;
            default:// Closes the program if a number out of range is entered
                cout << "  Press enter to close." << endl;
                getch();
                return 0; //<-- added return 0 to stop program

        }

        cout << "  Enter a number from 0 to 3 to set the speed. Enter a number out of range to exit: ";
        cin >> userSelection;
    }
}