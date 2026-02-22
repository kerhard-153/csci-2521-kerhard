/**
 * @file Lab5_kerhard.cpp
 * @author Kate Erhard
 * @date 2026-02-22
 * @brief A modular program to generate a multiplication table using functions.
 */

#include <iostream>

/**
* @breif Outputs an error message if user provides invalid input
* @param None.
* @return None (void).
*/
void printInputValidationError()
{
	std::cout << "Error: The max digit must be greater than 4 and less than 10. Please try again." << std::endl;
}

/**
* @breif Validates user input based on the range of digits
* @param input - the user's integer to validate.
* @return true if the user input is greater than 4 and less than 10. if otherwise, false.
*/
bool isMaxDigitInputValid(int input)
{
	return (input > 4 && input < 10);
}

/**
* @breif Prompts the user for input and validates it
* @param None.
* @return A valid int representing the maximum digit.
*/
int getMaxDigitInput() {
	
	int maxDigit;

	std::cout << "Please enter the maximum digit for the multiplication table." << std::endl;
	std::cout << "The digit must be greater than 4 and less than 10." << std::endl;

	while (true) {

		std::cout << "Max Digit: ";
		std::cin >> maxDigit;

		if (isMaxDigitInputValid(maxDigit)) {

			return maxDigit;
		}
		else {
			printInputValidationError();
		}
	}
}

/**
* @breif Prints the formatted multiplication table
* @param maxDigit - the highest digit to include in the table.
* @return None (void).
*/
void printMultiplicationTable(int maxDigit) {

	for (int i = 1; i <= maxDigit; i++)
	{
		for (int j = 1; j <= maxDigit; j++)
		{
			std::cout << i * j << "\t";
		}
		std::cout << std::endl;
	}
}

/**
* @breif Program entry point
* @param None.
* @return 0 to indicate success.
*/
int main() {

	int maxDigit = getMaxDigitInput();
	printMultiplicationTable(maxDigit);

	return 0;
}