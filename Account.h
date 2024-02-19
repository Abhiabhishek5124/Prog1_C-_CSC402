
#ifndef PROGRAM_1_ACCOUNT_H
#define PROGRAM_1_ACCOUNT_H
#include <string>
using namespace std;

class Account {
private:
    string accountID;
    string accountPIN;
    double accountBalance;

public:
    Account();
    Account(string id, string pin, double balance);

    string getID() const;
    void setID(string id);

    string getPIN() const;
    void setPIN(string pin);

    double getBalance() const;
    void setBalance(double balance);

    void Balance() const;
    void Deposit(double amt);
    void Withdraw(double amt);
};


#endif //PROGRAM_1_ACCOUNT_H
