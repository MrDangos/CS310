// Author: Hugo Ramirez
// Date: 05/17/2026
// Description: This program use BankAccount as a base class and create two classes, CheckingAccount and SavingsAccount. 
// It uses inheritance, virtual functions, and polymorphism.
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    protected:
        static int nextAccountNum;
        string accountName;
        int accountNum;
        double accountBlance;
        double interestRate;

    public:
    // Default constructor 
    BankAccount() {
        accountName = "Unknown";
        accountNum = nextAccountNum++;  
        accountBlance = 0.0;
        interestRate = 0.0;
    }

    // Constructor 
    BankAccount(string name, double blance, double rate) {
        accountName = name;
        accountNum = nextAccountNum++;  
        accountBlance = blance;
        interestRate = rate;
    }

    virtual string getAccountType() = 0;

    // AccountName
    void setAccountName(string name) { 
        accountName = name; 
    }

    // AccountNum
    int getAccountNum() { 
        return accountNum;
    }

    // Balance
    double getBalance() {
        return accountBlance;
    }

    void setBalance(double bal) { 
        accountBlance = bal;
    }

    // InterestRate
    double getInterestRate() {
        return interestRate;
    }

    void setInterestRate(double rate) {
        interestRate = rate; 
    }

    // Utility 
    void deposit(double amount) { 
        accountBlance += amount; 
    }

    virtual void withdraw(double amount) {
        if (amount > accountBlance)
            cout << "Insufficient funds." << endl;
        else
            accountBlance -= amount;
    }

    virtual void applyInterest(double interestRate) { 
        accountBlance += accountBlance * interestRate; 
    }
    
    virtual void print() {
        cout << "Account #" << accountNum
             << " | Name: " << accountName
             << " | Balance: $" << accountBlance;
    }

};

class CheckingAccount : public BankAccount {
    double minBalance;
    double serviceFee;

    // Constructor
    public:   
    CheckingAccount(string name, double bal, double rate, double min, double fee) 
        : BankAccount(name, bal, rate) {  
        minBalance = min;   
        serviceFee = fee;    
    }

    // Getters and Setters
    string getAccountType() override {
        return "Checking";
    };

    double getMinBalance() {
        return minBalance;
    };
    void setMinBalance(double min) {
        minBalance = min;
    };
    double getServiceFee() {
        return serviceFee;
    };
    void setServiceFee(double fee) {
        serviceFee = fee;
    };

    // Utility
    void applyInterest(double interestRate) override { 
        BankAccount::applyInterest(interestRate); 
    }

    void withdraw(double amount) override {
        BankAccount::withdraw(amount);
        if (verifyMinBalance())
            accountBlance -= serviceFee;
    }

    bool verifyMinBalance() {
        return accountBlance < minBalance;  
    }

    void print() override {
        BankAccount::print();  
        cout << " | Type: " << getAccountType()
            << " | Service Fee: $" << (accountBlance < minBalance ? serviceFee : 0.0)
            << " | Interest Rate: " << interestRate * 100 << "%"
            << endl;  
    }

};

class SavingsAccount : public BankAccount {

    // Constructor
public:   
    SavingsAccount(string name, double bal, double rate) 
        : BankAccount(name, bal, rate) {}

    string getAccountType() override {
        return "Savings";
    };

    // Utility
    void applyInterest(double interestRate) override { 
        BankAccount::applyInterest(interestRate); 
    }

    void withdraw(double amount) override {
        if (accountBlance <= 0) {
            cout << "You have no funds." << endl;
        } else {
            accountBlance -= amount;
        }
    };

    void print() override {
        BankAccount::print();  
        cout << " | Type: " << getAccountType()
            << " | Interest Rate: " << interestRate * 100 << "%"
            << endl;  
    }

};
int BankAccount::nextAccountNum = 1000;  

int main() {
    BankAccount* accounts[10] = {nullptr};

    accounts[0] = new CheckingAccount("Alice", 500.00, 0.02, 100.0, 25.0);
    accounts[1] = new SavingsAccount("Bob", 1200.00, 0.035);
    accounts[2] = new CheckingAccount("Carol", 300.00, 0.015, 100.0, 25.0);

    accounts[0]->deposit(200.00);
    accounts[1]->applyInterest(10);
    accounts[2]->withdraw(300.00);

    for (int i = 0; i < 3; i++) { 
        accounts[i]->print();
    }
    for (int i = 0; i < 3; i++) {
        delete accounts[i];
    }

    return 0;
}

