// Author: Hugo Ramirez
// Date: 04/03/2025
// Description: Program calculates royalties for a book based on three different options and displays the results.
// and best option to the user.
// Option 1: The author is paid $5,000 upon delivery of the final manuscript and $20,000 when the novel is published.
// Option 2: The author is paid 12.5% of the net price of the novel for each copy of the novel sold. 
// Option 3: The author is paid 10% of the net price for the first 4,000 copies sold, and 14% of the net price for the copies sold over 4,000.
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Declared variables
    double netPrice=0, numSold=0, option1=25000, option2=0, option3=0, bestOption=0;
    string bestOutput;

    // Input from user
    cout << "Type price of books \n";
    cin >> netPrice;
    cout << "Type estamated number of books sold \n";
    cin >> numSold;

    // Calculate royalties for each option
    option2 = netPrice * .125 * numSold;

    if (numSold <= 4000){
        option3 = 4000 * netPrice * .1;
    } else {
        option3 = ((numSold - 4000) * netPrice * .14) + (4000 * netPrice * .1);
    }

    // Determine the best option
    bestOption = max ({option1, option2, option3});

    if (bestOption == option1){
        bestOutput = "Option 1";
    } else if (bestOption == option2){
        bestOutput = "Option 2";
    } else {
        bestOutput = "Option 3";
    }

    // Display the results
    cout << "\nOption 1: $" << option1 << endl;
    cout << "Option 2: $" << option2 << endl;
    cout << "Option 3: $" << option3 << endl;
    cout << "\nYour Best Options is " << bestOutput << " with $" << bestOption << endl;
    return 0;
}