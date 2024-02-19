
#ifndef PROGRAM_1_BANK_H
#define PROGRAM_1_BANK_H
using namespace std;

#include "Account.h"
#include <vector>
#include <fstream>

class Bank {
private:
    vector<Account> allAccounts;
    Account dummyAccount; // New data member

public:
    Bank();
    // Getter for the length of allAccounts
    int getAllAccountsLength() const;

    Account& findAcct(string id, string pin);
    void addAcct(Account& acct);
    void loadAccounts(ifstream& inf);
};

#endif //PROGRAM_1_BANK_H
