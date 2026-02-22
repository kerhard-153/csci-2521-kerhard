/**
 * @file Lab5_kerhard.cpp
 * @author Kate Erhard
 * @date 2026-02-22
 * @brief A modular program to generate a multiplication table using functions.
 */

#include <iostream>

void printInputValidationError()
{
	std::cout << "Error: The max digit must be greater than 4 and less than 10. Please try again." << std::endl;
}

bool isMaxDigitInputValid(int input)
{
	return (input > 4 && input < 10);
}

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

int main() {

	int maxDigit = getMaxDigitInput();
	printMultiplicationTable(maxDigit);

	return 0;
}