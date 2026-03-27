#include <iostream>
using namespace std;

int main() {

    int num1, num2;
    double result;

    cout << "Enter first number: ";
    cin >> num1;  /** the error was for cin you need 2 right arrows (>>) not the 2 left arrows (<<).
                    2 left arrows are used for cout */
    cout << "Enter second number: ";
    cin >> num2;

    result = num1 / num2;

    cout << "The result of dividing " << num1 << " by " << num2
        << " is: " << result << endl; /** this cout statment had 2 errors. the worng arrows where used
                                        and there was a missing semi colen at the end of the cout statment*/ 

    return 0;
}