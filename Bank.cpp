
#include "Bank.h"
using namespace std;

// Constructor
Bank::Bank() {
    // Initialize dummyAccount with default values
    dummyAccount = Account();
}

// Getter method to retrieve the number of accounts in the Bank
int Bank::getAllAccountsLength() const {
    return allAccounts.size();
}

// Find and return an account based on the provided ID and PIN
Account& Bank::findAcct(string id, string pin) {
    for (Account& account : allAccounts) {
        if (account.getID() == id && account.getPIN() == pin) {
            return account;
        }
    }
    // If no matching account found, return the dummyAccount
    return dummyAccount;
}

// Add an account to the Bank
void Bank::addAcct(Account& acct) {
    allAccounts.push_back(acct);
}

// Load accounts from an input file stream into the Bank
void Bank::loadAccounts(ifstream& inf) {
    string id, pin;
    double balance;

    // Read account information from the input file stream
    while (inf >> id >> pin >> balance) {
        // Create a new Account object and add it to the Bank
        Account newAccount(id, pin, balance);
        addAcct(newAccount);
    }
}