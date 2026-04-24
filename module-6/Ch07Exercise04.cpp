// Author: Hugo Ramirez
// Date: 04/24/2026
// Description: checks user input for vowels and removes them from the string using substr, then outputs the modified string without vowels.
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch)
{
    ch = tolower(ch);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        return true;
    } else {
        return false;
    }
}

string removeVowels(string userInput)
{
    int i = 0;
    while (i < userInput.length())
    {
        if (isVowel(userInput[i]))
        {
            userInput = userInput.substr(0, i) + userInput.substr(i + 1);
        }
        else
        {
            i++;
        }
    }
    return userInput;
}

int main()
{
    string userInput, result;

    cout << "Enter a string: ";
    cin >> userInput;

    result = removeVowels(userInput);

    cout << "String after removing vowels: " << result << endl;

    return 0;
}