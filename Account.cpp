

#include "Account.h"
#include <iostream>
using namespace std;

// Default constructor initializes an Account object with empty ID, empty PIN, and zero balance
Account::Account() : accountID(""), accountPIN(""), accountBalance(0.0) {}


// Parameterized constructor validates the input parameters and initializes an Account object

Account::Account(string id, string pin, double balance) {
    if (id.length() == 8 && pin.length() == 4) {
        // Validate PIN format
        bool validPin = true;
        for (char character : pin) {
            if (!isdigit(character)) {
                validPin = false;
                break;
            }
        }

        // Validate PIN and balance, and initialize the Account object if valid
        if (validPin && balance >= 0.0) {
            accountID = id;
            accountPIN = pin;
            accountBalance = balance;
        } else {
            cout << "Invalid arguments for account creation." << endl;
        }
    } else {
        cout << "Invalid arguments for account creation." << endl;
    }
}

// Getter method for retrieving the account ID
string Account::getID() const {
    return accountID;
}

// Setter method for updating the account ID
void Account::setID(string id) {
    accountID = id;
}

// Getter method for retrieving the account PIN
string Account::getPIN() const {
    return accountPIN;
}

// Setter method for updating the account PIN
void Account::setPIN(string pin) {
    accountPIN = pin;
}

// Getter method for retrieving the account balance
double Account::getBalance() const {
    return accountBalance;
}

// Setter method for updating the account balance
void Account::setBalance(double balance) {
    accountBalance = balance;
}

// Display the account balance
void Account::Balance() const {
    cout << "Balance: $" << accountBalance << endl<<endl;
}

// Deposit funds into the account
void Account::Deposit(double amt) {
    if (amt >= 0.0) {
        accountBalance += amt;
        cout << "Deposit successful." << endl;
    } else {
        cout << "Invalid deposit amount." << endl;
    }
}

// Withdraw funds from the account
void Account::Withdraw(double amt) {
    if (amt > 0.0 && amt <= accountBalance) {
        accountBalance -= amt;
        cout << endl;
    } else {
        cout << "Invalid withdrawal amount." << endl<<endl;
    }
}
