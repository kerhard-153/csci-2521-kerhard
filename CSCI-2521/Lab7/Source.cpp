/**
 * @file Source.cpp
 * @author Kate Erhard
 * @date 2026-03-15
 * @brief A banking simulation interacting with Account and Customer objects.
 */
#include<iostream>
#include "Account.h"

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

/**
 * @brief Entry point for the banking application.
 * Allows deposits, withdrawals, and close-of-business processing
 * for a simulated bank account.
 * @return 0 when program is sucessful.
 */

int main()
{
    // just use dummy data for now for the customer and the account
    // we care about interacting with account object for this lab
    Customer customer("0123456789", "customer@cscc.edu");
    Account account("5423678409", 100.00, customer);
    account.printAccountInfo();

    int menuChoice = getMenuOption();
    
    while (menuChoice != QUIT)
    {
        switch (menuChoice)
        {
        case DEPOSIT:
        {
            double amount;

            cout << "Enter deposit amount: ";
            cin >> amount;

            if (isAmountValid(amount))
            {
                account.deposit(amount);
            }
            else
            {
                cout << "Invalid deposit amount." << endl;
            }

            break;
        }

        case WITHDRAWAL:
        {

            double amount;

            cout << "Enter withdrawal amount: ";
            cin >> amount;

            if (isAmountValid(amount))
            {
                account.withdraw(amount);
            }
            else
            {
                cout << "Invalid withdrawal amount." << endl;
            }

            break;
        }

        case CLOSE_OF_BUSINESS:
        {
            account.closeOfBusiness();
            break;

        }
        }

        menuChoice = getMenuOption();
    }
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