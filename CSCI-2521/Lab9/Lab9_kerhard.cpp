/**
 * @file Lab9_kerhard.cpp
 * @author Kate Erhard
 * @date 2026-04-11
 * @brief Demonstrates inheritance and polymorphism in a banking system.
 */


#include<iostream>
#include <numeric>
#include "Account.h"

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();
double getDepositAmount();
double getWithdrawalAmount();
void printInvalidAmountMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

/**
 * @class SavingsAccount
 * @brief Derived class that applies daily interest.
 */
class SavingsAccount : public Account {
private:
    double dailyInterestRate;

public:
    /**
     * @brief Constructor for SavingsAccount
     */
    SavingsAccount(const string& accNum, double initialBalance,
        const Customer& customer, double rate)
        : Account(accNum, initialBalance, customer)
    {
        dailyInterestRate = rate;
    }

    /**
     * @brief Overrides closeOfBusiness to include interest
     */
    void closeOfBusiness() override
    {
        double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
        double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

        double previousBalance = balance;
        double newBalance = previousBalance + totalDeposits - totalWithdrawals;

        if (newBalance > 0)
        {
            newBalance += newBalance * dailyInterestRate;
        }

        printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

        balance = newBalance;

        deposits.clear();
        withdrawals.clear();
    }

    /**
     * @brief Prints account info including interest
     */
    void printAccountInfo() const override
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "Interest Rate: " << dailyInterestRate * 100 << "%" << endl;

        owner.printCustomerInfo();
    }
};

int main()
{
    // just use dummy data for now for the customer and the account
    // we care about interacting with account object for this lab
    Customer customer("0123456789", "customer@cscc.edu");
    Account* account = new SavingsAccount("5423678409", 100.00, customer, 0.02);
    account->printAccountInfo();

    int menuChoice = getMenuOption();
    while (menuChoice != QUIT)
    {
        double deposit = 0, withdrawal = 0;

        switch (menuChoice)
        {
        case DEPOSIT:
            deposit = getDepositAmount();
            account->deposit(deposit);
            break;
        case WITHDRAWAL:
            withdrawal = getWithdrawalAmount();
            account->withdraw(withdrawal);
            break;
        case CLOSE_OF_BUSINESS:
            account->closeOfBusiness();
            break;
        }

        menuChoice = getMenuOption();
    }

    delete account;
}

void printMenu()
{
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << QUIT << ". Quit" << endl;
}

int getMenuOption()
{
    int choice = 0;

    do
    {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }
    } while (!isMenuChoiceValid(choice));

    return choice;
}

bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT and choice <= QUIT;
}

bool isAmountValid(double amount)
{
    return amount > 0;
}

void printInvalidMenuChoiceMessage()
{
    cout << "Invalid option selected. Please try again." << endl;
}

double getDepositAmount()
{
    double deposit = 0;
    do
    {
        cout << "Please enter the deposit amount: $";
        cin >> deposit;

        if (!isAmountValid(deposit))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(deposit));

    return deposit;
}

double getWithdrawalAmount()
{
    double withdrawal = 0;
    do
    {
        cout << "Please enter the withdrawal amount: $";
        cin >> withdrawal;

        if (!isAmountValid(withdrawal))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(withdrawal));

    return withdrawal;
}

void printInvalidAmountMessage()
{
    cout << "The dollar amount must be greater than $0.00. Please try again." << endl;
}