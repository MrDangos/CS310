/*
*Student Name: Daniel Preller
*File Name: Week1.cpp
*Date: 3/25/2026
*
*Corrected by Hugo Ramirez
*Date: 3/28/2026
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    //Gets first user input
    int value1; //value1 was not delared
    cout << "\n\n  Please enter an integer: ";
    cin >> value1;

    //Gets second user input <-- wrong comment format
    int value2;
    cout << "\n\n  Please enter another integer: ";
    cin >> value2;

    cout << "\n\n  " << value1 << " times " << value2 << " equals " << value1 * value2 << endl;//Prints results
    getch();//Stops execution until user presses enter
    // cout is << not >>
}