/**
 * @file Lab6_kerhard.cpp
 * @author Kate Erhard
 * @date 2026-03-01
 * @brief Compare static arrays and vectors for processing student scores.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * @brief Calculates statistics using a fixed-size static array.
 * @param None.
 * @return None.
 */
void arraySolution()
{
    const int SIZE = 10;
    int scores[SIZE];

    cout << " Static Array Solution \n" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        int input;
        while (true)
        {
            cout << "Enter score " << (i + 1) << " (0-100): ";
            cin >> input;

            if (input >= 0 && input <= 100)
            {
                scores[i] = input;
                break;
            }
            else
            {
                cout << "Invalid input. Please enter a score between 0 and 100." << endl;
            }
        }
    }

    int sum = 0;
    int highest = scores[0];
    int lowest = scores[0];

    for (int i = 0; i < SIZE; i++)
    {
        sum += scores[i];

        if (scores[i] > highest)
        {
            highest = scores[i];
        }

        if (scores[i] < lowest)
        {
            lowest = scores[i];
        }
    }

    float average = static_cast<float>(sum) / SIZE;

    cout << "\nArray Statistics:" << endl;
    cout << "Average Score: " << average << endl;
    cout << "Highest Score: " << highest << endl;
    cout << "Lowest Score: " << lowest << endl;
}

/**
 * @brief Calculates statistics using a dynamic vector.
 * @param None.
 * @return None.
 */
void vectorSolution()
{
    vector<int> scores;
    int input;

    cout << "\n Vector Solution \n" << endl;
    cout << "Enter scores between 0 and 100 (-1 to stop):" << endl;

    while (true)
    {
        cout << "Enter score: ";
        cin >> input;

        if (input == -1)
        {
            break;
        }
        else if (input >= 0 && input <= 100)
        {
            scores.push_back(input);
        }
        else
        {
            cout << "Invalid input. Please enter a score between 0 and 100 or -1 to finish." << endl;
        }
    }

    if (scores.empty())
    {
        cout << "No scores were entered." << endl;
        return;
    }

    int sum = 0;
    int highest = scores[0];
    int lowest = scores[0];

    for (size_t i = 0; i < scores.size(); i++)
    {
        sum += scores[i];

        if (scores[i] > highest)
        {
            highest = scores[i];
        }

        if (scores[i] < lowest)
        {
            lowest = scores[i];
        }
    }

    float average = static_cast<float>(sum) / scores.size();

    sort(scores.begin(), scores.end());

    cout << "\nVector Statistics:" << endl;
    cout << "Average Score: " << average << endl;
    cout << "Highest Score: " << highest << endl;
    cout << "Lowest Score: " << lowest << endl;

    cout << "Sorted Scores (Ascending): ";
    for (size_t i = 0; i < scores.size(); i++)
    {
        cout << scores[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Entry point of the program.
 * @param None.
 * @return 0 to indicate success.
 */
int main()
{
    arraySolution();
    vectorSolution();
    return 0;
}
