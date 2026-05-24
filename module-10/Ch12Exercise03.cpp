// Author: Hugo Ramirez
// Date: 05/21/2026
// Description: updated election results program to use dynamic arrays
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int getCandidates(string* candidates, int* votes, int numCandidates)
{
    int totalVotes = 0;

    for (int i = 0; i < numCandidates; i++)
    {
        cout << "\nEnter name for candidate " << (i + 1) << ": ";
        cin >> candidates[i];

        cout << "Enter the number of votes for " << candidates[i] << ": ";
        cin >> votes[i];

        totalVotes += votes[i];
    }

    return totalVotes;
}

int main()
{
    int numCandidates;

    cout << "How many candidates are in the election? ";
    cin >> numCandidates;

    string* candidates  = new string[numCandidates];
    int*    votes       = new int[numCandidates];
    double* percentages = new double[numCandidates];

    int totalVotes = getCandidates(candidates, votes, numCandidates);

    string winner;
    for (int i = 0; i < numCandidates; i++)
    {
        percentages[i] = (static_cast<double>(votes[i]) / totalVotes) * 100.0;

        if (i == 0 || percentages[i] > percentages[i - 1])
            winner = candidates[i];
    }

    cout << "\nElection Results:\n";
    for (int i = 0; i < numCandidates; i++)
    {
        cout << left  << setw(20) << candidates[i]
             << "Votes: " << right << setw(6) << votes[i]
             << "    Percent: " << fixed << setprecision(2) << setw(6) << percentages[i] << "%"
             << endl;
    }
    cout << "Total Votes:    " << totalVotes << endl;
    cout << "\nThe Winner of the Election is " << winner << endl;

    delete[] candidates;
    delete[] votes;
    delete[] percentages;

    return 0;
}