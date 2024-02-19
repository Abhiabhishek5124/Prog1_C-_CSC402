/*
  Author: Abhishek Shrestha
  CSC 402 - Program #1
  Basic Bank ATM System

  Program Description:
  This program implements a basic Bank ATM system with three classes:
  Account, Bank, and ATM. It allows users to interact with individual bank accounts,
  checking balances, making deposits, and performing withdrawals.
  The Bank class manages all accounts, loading them from an input file, and
  the ATM class facilitates user interactions such as logging in and conducting transactions.
  Users can quit the system or exit gracefully after interacting with their account.
  The program demonstrates file I/O, vector usage, and class functionalities.

  Date: 01/29/2024
*/


#include <iostream>
#include <fstream>
#include "Bank.h"
#include "ATM.h"
using namespace std;

int main() {

    // Declare input file stream and Bank object
    ifstream inf;
    Bank bk;

    // Prompt user for the path to the account information file
    cout << "Enter path for account information : ";
    string filePath;
    cin >> filePath;

    // Open the specified file
    inf.open(filePath);

    // Check if the file is successfully opened
    if (!inf) {
        cout << "Error opening file. Exiting." << endl;
        return 1;
    }

    // Load account information from the file into the Bank object
    bk.loadAccounts(inf);
    inf.close();

    // Display loading message and the number of accounts loaded
    cout << "Loading Data..." <<endl;
    cout << bk.getAllAccountsLength() << " Accounts loaded." << endl<<endl;

    // Create ATM object with the loaded Bank object
    ATM atm(bk);

    // Start the ATM simulation and store the result
    int result = atm.start();


    // Display messages based on the result of the ATM simulation
    switch (result) {
        case 0:
            cout << "Normal Exit." << endl;
            break;
        case 1:
            cout << "Account not found - system shutting down" << endl;
            break;
    }

    return 0;
}