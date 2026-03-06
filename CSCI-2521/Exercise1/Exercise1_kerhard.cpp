/**
 * @file Exercise1_kerhard.cpp
 * @author Kate Erhard
 * @date 2026-03-03
 * @brief This program validates UPC-A barcodes performing the UPC-A check digit algorithm.
 */


#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Calculates the UPC check digit based on the first 11 digits.
 * @param upc The UPC code as a string.
 * @return int The calculated check digit.
 */

int calculateCheckDigit(string upc) {
	
	int oddSum = 0;
	int evenSum = 0;

	for (int i = 0; i < 11; i++) {
		int digit = upc[i] - '0';

		if (i % 2 == 0) {
			oddSum += digit;
		}
		else {
			evenSum += digit;
		}
	}

	int result = (oddSum * 3) + evenSum;
	int mod = result % 10;

	if (mod == 0) {
		return 0;
	}
	else {
		return 10 - mod;
	}
}

/**
 * @brief Checks if the provided UPC code is valid.
 * @param upc The UPC code entered by the user.
 * @return bool True if valid UPC, false if invalid UPC.
 */

bool isValidUPC(string upc) {

	int checkDigit = upc[11] - '0';
	int calculatedDigit = calculateCheckDigit(upc);

	return checkDigit == calculatedDigit;
}

/**
 * @brief Prompts the user for the parts of the UPC code.
 * @return string The combination of the UPC parts entered by the user to
 * make the full code.
 */

string getUPC() {

	string firstDigit;
	string manufacturerNum;
	string productNum;
	string checkDigit;

	cout << "Enter the first digit: ";
	cin >> firstDigit;

	cout << "Enter 5-digit manufacturer number (first set of 5 digits): ";
	cin >> manufacturerNum;

	cout << "Enter 5-digit product number (second set of 5 digits): ";
	cin >> productNum;

	cout << "Enter the last digit: ";
	cin >> checkDigit;

	return firstDigit + manufacturerNum + productNum + checkDigit;
}

/**
 * @brief Main function that runs the UPC validation program.
 */

int main() {
	char choice = 'y';

	cout << "Do you have a UPC number to test? (y/n): ";
	cin >> choice;

	while (choice == 'y' || choice == 'Y') {

		string upc = getUPC();

		if (upc.length() != 12) {
			
			cout << "UPC must be exactly 12 digits.\n";
		}
		else if (isValidUPC(upc)) {

			cout << "\nUPC code is valid.\n";
		}
		else {

			cout << "\nUPC code is invalid.\n";
		}

		cout << "\nDo you want to validate another UPC code? (y/n): ";
		cin >> choice;
		cout << endl;
	}

	cout << "Goodbye\n";
	return 0;
}