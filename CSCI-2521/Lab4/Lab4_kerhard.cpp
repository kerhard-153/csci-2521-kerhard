/**
 * @file Lab4_kerhard.cpp
 * @author Kate Erhard
 * @date 2026-02-15
 * @brief A program to generate a multiplication table with input validation.
 */

#include <iostream>
using namespace std;

int main()
{
	int maxDigit;

	cout << "Please enter the maximum digit for the multiplication table." << endl;
	cout << "The digit must be greater than 4 and less than 10" << endl;

    do
    {
        cout << "Max Digit: ";
        cin >> maxDigit;

        if (maxDigit <= 4 || maxDigit >= 10)
        {
            cout << "Error: The max digit must be greater than 4 and less than 10. Please try again." << endl;
        }

    } while (maxDigit <= 4 || maxDigit >= 10);


    for (int i = 1; i <= maxDigit; i++)
    {
        for (int j = 1; j <= maxDigit; j++)
        {
            cout << i * j << "\t";
        }
        cout << endl;
    }

    return 0;
}