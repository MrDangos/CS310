// Author: Hugo Ramirez
// Date: 04/07/2025
// Description: asks user to input the time to prepare the first dish, the time to prepare each additional dish, and the total time available. 
// It then calculates and outputs how many dishes can be prepared within the given time.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Declare variables
    int a=0, b=0, nextDishTime=0, numDishes=1, time=0, totalTime=0;

        // Get user input
        cout << "Minutes to perapre first dish \n";
        cin >> a;
        cout << "How long to make next dish \n";
        cin >> b;
        cout << "amount of time you have \n";
        cin >> time;

        // Calcs
        nextDishTime = a + b;
        totalTime += nextDishTime;

        while (totalTime <= time){
            nextDishTime = nextDishTime + b;
            totalTime += nextDishTime;
            if (totalTime<= time)
            {
                numDishes++;
            }    
        };

        // Output
        cout << "The number of dishes you make in " << time << " minutes is " << numDishes << " dishes" << endl;

    return 0;
}