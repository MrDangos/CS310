// Author: Hugo Ramirez
// Date: 04/27/2026
// Description: This program allows the user to enter candidate names and their corresponding 
//  votes, calculates the total votes, percentages, and determines the winner of the election.
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

vector<string> candidates;
vector<int> votes;
vector<double> percentages;  

// Function to get candidate names and votes, and calculate total votes
double getCandidates(double totalVotes)
{
    char answer = 'y';
    string name;
    int voteCount;

    while (answer == 'y')
    {
        cout << "\nEnter candidate name: ";
        cin >> name;
        candidates.push_back(name);

        cout << "Enter the number of votes for " << name << ": ";
        cin >> voteCount;
        votes.push_back(voteCount);

        totalVotes += voteCount;

        cout << "\nDo you want to enter another candidate? (y/n): ";
        cin >> answer;
    }
    return totalVotes;
}

int main()
{
    string winner;
    double totalVotes = 0;

    totalVotes = getCandidates(totalVotes);

    int numCandidates = candidates.size();  

    // Calculate percentages and determine the winner
    for (int i = 0; i < numCandidates; i++)
    {
        percentages.push_back((votes[i] / totalVotes) * 100); 
        if (i == 0) 
        {
            winner = candidates[i];
        }
        else if (percentages[i] > percentages[i-1]) 
        {
            winner = candidates[i];
        }

    }
    
    // Display results
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

    return 0;
}