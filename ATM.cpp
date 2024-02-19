
#include "ATM.h"
#include <iostream>
using namespace std;

// Constructor
ATM::ATM(Bank& bank) : bank(bank) {}

// Member function to start the ATM
int ATM::start() {
    char choice;
    int loginAttempts = 0;
    
       // Main loop for the ATM functionality
    while (true) {
        cout << "Please enter your command" << endl << "Q - quit/exit" << endl << "L - login to account" << endl;
        cin >> choice;
        cout << endl;

        if (choice == 'Q') {
            return 0;  // Normal Exit
        } else if (choice == 'L') {
            string id, pin;
            loginAttempts = 0;

           // Loop for account login with limited attempts
            while (loginAttempts < 3) {
                cout << "Please enter Account ID" << endl;
                cin >> id;
                cout << "Please enter PIN"<< endl;
                cin >> pin;

                Account& userAccount = bank.findAcct(id, pin);

                if (!userAccount.getID().empty()) {
                    cout<<"Account found"<< endl<<endl;
                    transactions(userAccount);
                    break;
                } else {
                    cout << "Sorry – no match" << endl<<endl;
                    loginAttempts++;
                }
            }

            if (loginAttempts == 3) {
                cout << "Too many login attempts. Exiting." << endl;
                return 1;  // Account not found - system shutting down
            }
        } else {
            cout << "Invalid choice. Try again."<< endl;
        }
    }
}

// Member function for transactions
void ATM::transactions(Account& acct) {
    char choice;
    
       // Loop for transaction menu
    do {
        cout << "Please enter your selection or Q to quit." << endl<<endl;
        cout << "W - withdraw funds" << endl;
        cout << "D - deposit funds" << endl;
        cout << "B - check balance" << endl;
        cout << "Q - quit/exit" << endl;
        cin >> choice;

        // Process user's transaction choice
        switch (choice) {
            case 'W':
                double withdrawAmt;
                cout << "Please enter amount of withdrawal" <<endl;
                cin >> withdrawAmt;
                acct.Withdraw(withdrawAmt);
                break;
            case 'D':
                double depositAmt;
                cout << "Enter deposit amount: $";
                cin >> depositAmt;
                acct.Deposit(depositAmt);
                break;
            case 'B':
                acct.Balance();
                break;
            case 'Q':
                cout << "Goodbye." << endl<<endl;
                break;
            default:
                cout << "Unrecognized command "<<choice << endl<<endl;
        }
    } while (choice != 'Q');

}
