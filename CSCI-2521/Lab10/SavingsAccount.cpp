#include "SavingsAccount.h"
#include <fstream>
#include <iomanip>

SavingsAccount::SavingsAccount() : interest(1)
{
}

SavingsAccount::SavingsAccount(const string& accNum, double initialBalance, float interest, const Customer& customer)
    : Account(accNum, initialBalance, customer)
{    
    this->interest = interest;
}

void SavingsAccount::closeOfBusiness()
{
    double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
    double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

    double previousBalance = balance;
    double interestToApply = previousBalance <= 0 ? 0 : interest;
    double newBalance = (previousBalance + totalDeposits - totalWithdrawals) * (1 + interestToApply);

    printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

    balance = newBalance;

    deposits.clear();
    withdrawals.clear();
}

void SavingsAccount::printAccountInfo() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: $" << balance << endl;
    cout << "Interest Rate: " << interest * 100 << "%" << endl;
    owner.printCustomerInfo();
}

/**
 * @brief Saves the account information to a text file.
 */
void SavingsAccount::Save() const
{
    ofstream outFile("account_summary.txt");

    outFile << "Account Number: " << accountNumber << endl;
    outFile << endl;

    outFile << fixed << setprecision(2);
    outFile << "Current Balance: $" << balance << endl;
    outFile << endl;

    outFile << "Daily Interest Rate: " << interest << endl;

    outFile.close();
}