/**
* @file Lab1_kerhard.cpp
* @author Kate Erhard
* @date 2026-01-22
* @brief A simple program to greet the user by their name
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string firstName, lastName;

	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin >> lastName;
	cout << "Welcome to C++ Programming, " << firstName << " " << lastName << "!" << endl;

	return 0;

}
