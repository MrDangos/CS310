// Author: Hugo Ramirez
// Date: 04/07/2025
// Description: asks user to input the time to prepare the first dish, the time to prepare each additional dish, and the total time available. 
// It then calculates and outputs how many dishes can be prepared within the given time.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Declare variables
    int fistDish=0, nextDish=0, timeBetweenDishes=0, numDishes=1, time=0, totalTime=0;

        // Get user input
        cout << "Minutes to make first dish \n";
        cin >> fistDish;
        cout << "How long to make next dish \n";
        cin >> nextDish;
        cout << "amount of time you have \n";
        cin >> time;

        // Calcs
        nextDish = fistDish + nextDish;
        timeBetweenDishes = nextDish + fistDish;
        numDishes++;

        while (totalTime <= time){
            timeBetweenDishes = nextDish + nextDish;
            totalTime += timeBetweenDishes;
            if (totalTime<= time)
            {
                numDishes++;
            }    
        };

        // Output
        cout << "The number of dishes you make in " << time << " minutes is " << numDishes << " dishes" << endl;

    return 0;
}