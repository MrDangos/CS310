/*
 * Student Name: Daniel Preller
 * File Name: Week7.cpp
 * Date: 4/27/2026
 * 
 * Fixed by: Hugo Ramirez
 * Fix Date: 5/3/2024
*/

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

//Function prototype
int getInputInRange(int min, int max, string message);

int main() {
    //Gets the minimum base for the multiplication table
    string firstMessage = "Please enter a number between 0 and 5 as the minimum base in the multiplication table: ";
    int min = getInputInRange(0, 5, firstMessage);

    //Gets the maximum base for the multiplication table, which is always larger than the minimum
    string secondMessage = "Please enter a number between, " + to_string(min + 1) + " and 10 as the maximum base in the multiplication table: ";
    int max = getInputInRange(min + 1, 10, secondMessage);

    //Creates a table of sufficient size for the given input
    int size = max - min + 1;
    int table[size][size]; // FIX 1 (syntax): provided array dimensions

    //Populates the multiplication table
    for (int i = 0; i < size; i++) { // unchanged - was already correct
        for (int j = 0; j < size; j++) {
            table[i][j] = (i + min) * (j + min);
        }
    }

    //Outputs the table header
    cout << "  |";
    for (int i = min; i <= max; i++) {
        cout << setw(4) << i;
    }

    cout << endl;

    //Outputs a dividing line of a size matching the header
    for (int i = 0; i < (size * 4) + 4; i++) {
        cout << "-";
    }

    cout << endl; // FIX 2 (logic): added missing endl after divider

    //Outputs the multiplication table
    for (int i = 0; i < size; i++) {
        cout << setw(2) << i + min << "|";
        for (int j = 0; j < size; j++) { // FIX 3 (logic): changed <= to < to prevent out-of-bounds access
            cout << setw(4) << table[i][j];
        }
        cout << endl;
    }

    getch();

}

//Gets a value from the user in a specific range,
//and repeats until a valid input is provided
int getInputInRange(int min, int max, string message) {
    cout << message;
    int value;
    while (!(cin >> value && value >= min && value <= max)) {
        cout << "Error. Please enter a number between " << min << " and " << max << ": ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return value;
}