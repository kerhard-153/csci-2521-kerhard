/**
* @file Lab3_kerhard.cpp
* @author Kate Erhard
* @date 2026-02-05
* @brief A program to let the user choose a variety of options from a menu, and calculate
* the area of a rectangle, a circle, or quit the program. The user is prompted for input
* during the menu selection and the calculation based on what option was selected from the menu
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string selectionNum;
	double length, width, radius, area;
	const double PI = 3.141592;


	cout << "Menu" << endl;
	cout << "1. Calculate the Area of a Rectangle" << endl;
	cout << "2. Calculate the Area of a Circle" << endl;
	cout << "3. Quit" << endl;
	cout << "Please make a menu selection: ";

	cin >> selectionNum;


	if (selectionNum == "1") {
		cout << "Please enter the length of the rectangle: ";
		cin >> length;

		cout << "Please enter the width of the rectangle: ";
		cin >> width;

		area = length * width;

		cout << "The area of the rectangle is: " << area << endl;
	}
	else if (selectionNum == "2") {
		cout << "Please enter the radius of the circle: ";
		cin >> radius;

		area = PI * (radius * radius);

		cout << "The area of the circle is: " << area << endl;
	}
	else if (selectionNum == "3") {
		cout << "Thank you!" << endl;
		return 0;
	}
	else {
		cout << "Invalid selection. Please try again.";
		return 0;
	}

	return 0;

}