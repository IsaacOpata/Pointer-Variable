//Isaac Opata
//June 25, 2024
//Test Score Array Alocator

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double average(double*, int);
void sort(double*, int);

int main()
{
    int numTestScores = 0; // Variable to store the number of test scores
    double* testScorePtr = nullptr; // Pointer to dynamically allocate memory for test scores
    double testAv = 0; // Variable to store the average of the test scores

    // Prompt user to enter the number of test scores
    cout << "Enter the number of test scores: ";
    cin >> numTestScores;

    // Input validation: number of test scores cannot be negative
    while (numTestScores < 0)
    {
        cout << "Number of test scores cannot be negative. Reenter.\n";
        cout << "Enter another number: ";
        cin >> numTestScores;
    }

    // Dynamically allocate memory for the test scores
    testScorePtr = new double[numTestScores];

    // Loop to input each test score
    for (int i = 0; i < numTestScores; i++)
    {
        cout << "Enter test Score for test " << (i + 1) << ": ";
        cin >> testScorePtr[i];

        // Input validation: test scores must be positive
        while (testScorePtr[i] < 0)
        {
            cout << "Test scores must be positive. Reenter: ";
            cout << "Enter a valid test score: ";
            cin >> testScorePtr[i];
        }
    }

    // Sort the test scores in ascending order
    sort(testScorePtr, numTestScores);

    // Calculate the average of the test scores
    testAv = average(testScorePtr, numTestScores);

    // Output the test scores and their average
    cout << "\nThe test scores in ascending order and their averages are: \n\n";
    cout << "Score" << "\n";

    // Loop to print each test score
    for (int k = 0; k < numTestScores; k++)
    {
        cout << "\n" << fixed << setprecision(2) << showpoint << setw(5) << testScorePtr[k];
    }

    // Print the average test score
    cout << "\nAverage score: " << fixed << setprecision(2) << showpoint << testAv << endl;

    // Free the dynamically allocated memory
    delete[] testScorePtr;
    testScorePtr = nullptr;

    return 0;
}

// Function to calculate the average of the test scores
double average(double* score, int numOfScores)
{
    double total = 0.00; // Variable to store the sum of all test scores
    for (int j = 0; j < numOfScores; j++)
        total += score[j]; // Add each test score to the total
    return(total / numOfScores); // Return the average
}

// Function to sort the test scores in ascending order
void sort(double* score, int size)
{
    int start, minIndex; // Variables for the starting index and minimum index
    double minValue; // Variable to store the minimum value

    // Loop to move the boundary of the unsorted subarray
    for (start = 0; start < (size - 1); start++)
    {
        minIndex = start; // Assume the first element is the minimum
        minValue = score[start]; // Store the first element as the minimum value
        // Loop to find the minimum element in the unsorted subarray
        for (int index = start + 1; index < size; index++)
        {
            // If the current element is smaller than the minimum value, update minValue and minIndex
            if (score[index] < minValue)
            {
                minValue = score[index];
                minIndex = index;
            }
        }
        // Swap the found minimum element with the first element
        score[minIndex] = score[start];
        score[start] = minValue;
    }
}
