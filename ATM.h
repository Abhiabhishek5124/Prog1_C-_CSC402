
#ifndef PROGRAM_1_ATM_H
#define PROGRAM_1_ATM_H
#include "Bank.h"
using namespace std;

class ATM {
private:
    Bank& bank;

public:
    // Constructor
    ATM(Bank& bk);

    // Member function
    int start();
    void transactions(Account& acct);
};



#endif //PROGRAM_1_ATM_H
