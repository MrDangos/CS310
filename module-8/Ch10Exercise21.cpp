// Author: Hugo Ramirez
// Date: 05/10/2026
// Description: Files shows clases and data abstractions
#include <iostream>
#include <string>
using namespace std;

class BankAccount {

    static int nextAccountNum;
    string accountName;
    int accountNum;
    string accountType;
    double balance;
    double interestRate;

public:
    // Default constructor 
    BankAccount() {
        accountName = "Unknown";
        accountNum = nextAccountNum++;  
        accountType = "checking";
        balance = 0.0;
        interestRate = 0.0;
    }

    // Constructor 
    BankAccount(string name, string type, double bal, double rate) {
        accountName = name;
        accountNum = nextAccountNum++;  
        accountType = type;
        balance = bal;
        interestRate = rate;
    }

    // AccountName
    void setAccountName(string name) { 
        accountName = name; 
    }
    string getAccountName() {
        return accountName; 
    }

    // AccountNum
    int getAccountNum() { 
        return accountNum;
     }

    // AccountType
    void setAccountType(string type) {
        accountType = type; 
    }
    string getAccountType() { 
        return accountType; 
    }

    // Balance
    void setBalance(double bal) { 
        balance = bal; 
    }
    double getBalance() { 
        return balance; 
    }

    // InterestRate 
    void setInterestRate(double rate) { 
        interestRate = rate; 
    }
    double getInterestRate() { 
        return interestRate; 
    }

    // Utility functions
    void deposit(double amount) { 
        balance += amount; 
    }

    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient funds." << endl;
        else
            balance -= amount;
    }

    void applyInterest() { balance += balance * interestRate; }

    void print() {
        cout << "Account #" << accountNum
             << " | Name: " << accountName
             << " | Type: " << accountType
             << " | Balance: $" << balance
             << " | Rate: " << interestRate * 100 << "%" << endl;
    }
};

int BankAccount::nextAccountNum = 1000;  

int main() {
    BankAccount accounts[10];  

    accounts[0] = BankAccount("Alice", "checking", 500.00, 0.02);
    accounts[1] = BankAccount("Bob", "saving", 1200.00, 0.035);
    accounts[2] = BankAccount("Carol", "checking", 300.00, 0.015);

    accounts[0].deposit(200.00);
    accounts[1].applyInterest();
    accounts[2].withdraw(50.00);

    for (int i = 0; i < 10; i++) {
        accounts[i].print();
    }

    return 0;
}