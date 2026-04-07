// Author: Hugo Ramirez
// Date: 04/07/2025
// Description: 
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a=0, b=0, c=0, d=1, t=0, tt=0;

        cout << "Minutes to perapre first dish \n";
        cin >> a;
        cout << "How long to make next dish \n";
        cin >> b;
        cout << "amount of time you have \n";
        cin >> t;

        c = a + b;

        while (tt <= t){
            c = c + b;
            tt += c;
            d ++;
        }

        cout << "The number of dishes you make in " << t << " minutes is " << d << " dishes" << endl;

    return 0;
}