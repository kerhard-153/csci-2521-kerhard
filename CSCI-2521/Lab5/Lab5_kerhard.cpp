/**
 * @file Lab5_kerhard.cpp
 * @author Kate Erhard
 * @date 2026-02-22
 * @brief A modular program to generate a multiplication table using functions.
 */

#include <iostream>

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
			//print error
		}
	}
}

int main() {

	int maxDigit = getMaxDigitInput();

	return 0;
}