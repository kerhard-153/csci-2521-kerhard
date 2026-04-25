/**
 * @file Lab11_kerhard.cpp
 * @author Kate Erhard
 * @date 2026-04-25
 * @brief Demonstrates exception handling using std::vector and std::out_of_range
 * by retrieving Japanese city names based on user-provided index input.
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @brief Prompts the user for an index value.
 * @return The integer index entered by the user.
 */
int getUserIndex()
{
    int index;
    cout << "Enter an index to look up a city: ";
    cin >> index;
    return index;
}

/**
 * @brief Displays a city from the vector based on the user index.
 * Handles out_of_range exceptions and displays the first or last city
 * depending on the out_of_range value.
 *
 * @param cities - A vector containing city names.
 * @param index - The index to access in the vector.
 * @return void
 */
void displayCity(const vector<string>& cities, int index)
{
    try
    {
        string city = cities.at(index);
        cout << "City at index " << index << " is: " << city << endl;
    }
    catch (out_of_range&)
    {
        if (index < 0)
        {
            cout << "Invalid index. Here's the first city instead: "
                << cities.front() << endl;
        }
        else if (index >= cities.size())
        {
            cout << "Invalid index. Here's the last city instead: "
                << cities.back() << endl;
        }
    }
}

/**
 * @brief Entry point of the program. Creates a vector of Japanese cities,
 * prompts the user for an index, and displays the result.
 * @return 0 to indicate success.
 */
int main()
{
    vector<string> cities = {
        "Tokyo",
        "Kyoto",
        "Osaka",
        "Sapporo",
        "Nagoya",
        "Fukuoka",
        "Nagasaki"
    };

    int index = getUserIndex();
    displayCity(cities, index);

    return 0;
}
