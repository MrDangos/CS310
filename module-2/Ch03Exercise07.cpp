#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double netBalance, payment, d1, d2, interest, averageDailyBalance, interestRate;
    cout << "Type net balance \n";
    cin >> netBalance;
    cout << "Type payment amount \n";
    cin >> payment;
    cout << "Type number of days in billing cycle \n";
    cin >> d1;
    cout << "Type number of days payment was made before billing cycle \n";
    cin >> d2;
    cout << "Type interest rate \n";
    cin >> interestRate;

    averageDailyBalance = (netBalance*d1 - payment*d2)/d1;
    interest = averageDailyBalance*interestRate;

    cout << "Average daily balance is " << setprecision(2) << averageDailyBalance << endl;
    cout << "Interest is " << setprecision(3) << interest << endl;
    return 0;
}