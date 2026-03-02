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
 * @brief Calculates the average of the scores in a static array.
 * @param arr The array containing int scores.
 * @param size The num of elements in the array.
 * @return average score as a float.
 */
float calculateAverage(const int arr[], int size) {
    
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return static_cast<float>(sum) / size;
}

/**
 * @brief Finds the max score in a static array.
 * @param arr The array containing int scores.
 * @param size The num of elements in the array.
 * @return The highest score.
 */
int findMax(const int arr[], int size)
{
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

/**
 * @brief Finds the min score in a static array.
 * @param arr The array containing int scores.
 * @param size The num of elements in the array.
 * @return The lowest score.
 */
int findMin(const int arr[], int size)
{
    int minVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }
    return minVal;
}

/**
 * @brief Calculates the average of the scores in a vector.
 * @param vec The vector containing int scores.
 * @return The average score as a float.
 */
float calculateAverage(const vector<int>& vec)
{
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }
    return static_cast<float>(sum) / vec.size();
}

/**
 * @brief Finds the max score in a vector.
 * @param vec The vector containing int scores.
 * @return The highest score.
 */
int findMax(const vector<int>& vec)
{
    int maxVal = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] > maxVal)
        {
            maxVal = vec[i];
        }
    }
    return maxVal;
}

/**
 * @brief Finds the min score in a vector.
 * @param vec The vector containing int scores.
 * @return The lowest score.
 */
int findMin(const vector<int>& vec)
{
    int minVal = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] < minVal)
        {
            minVal = vec[i];
        }
    }
    return minVal;
}

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

    float average = calculateAverage(scores, SIZE);
    int highest = findMax(scores, SIZE);
    int lowest = findMin(scores, SIZE);

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

    float average = calculateAverage(scores);
    int highest = findMax(scores);
    int lowest = findMin(scores);

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
