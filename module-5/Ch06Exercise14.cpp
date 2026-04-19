// Author: Hugo Ramirez
// Date: 04/14/2026
// Description: calculates the bill for a client based on the hourly rate and time spent on the service.
#include <iostream>
#include <iomanip>
using namespace std;

double calc(double hourlyRate, double time, bool lowIncome) {
    double overtime, discountRate;
    if (lowIncome) {
        overtime = time - 30;
        discountRate = hourlyRate * 0.40;
    } else {
        overtime = time - 20;
        discountRate = hourlyRate * 0.70;
    }
    if (overtime <= 0) return 0;
    return discountRate * (overtime / 60);
}

int main() {
    // Declare variables
    double hourlyRate=0, income=0, time=0, bill=0, discountRate=0;
        // Get user input
        cout << "What is your hourly rate \n";
        cin >> hourlyRate;
        cout << "How much does your client make\n";
        cin >> income;
        cout << "How long did it last in minutes\n";
        cin >> time;

        if (income <= 25000){
            bill = calc(hourlyRate, time, true);
        } else {
            bill = calc(hourlyRate, time, false);
        };
 
        // Output
        cout << "\nBill is: $" << fixed << setprecision(2) << bill << endl;
    return 0;
}
