
/*
  Problem Statement:
  Create a function template for Bubble Sort that
  accepts an array of integers or floats, sorts the
  elements in ascending order, and displays the
  sorted array.

  CO2087
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function Template for Bubble Sort
template <typename T>
void sortArray(T arr[], int n)
{
    // Repeat passes through the array
    for (int i = 0; i < n - 1; i++)
    {
        // Compare adjacent elements
        for (int j = 0; j < n - i - 1; j++)
        {
            // Swap if elements are in wrong order
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Integer array
    int intArr[] = {64, 25, 12, 22, 11};
    int n1 = 5;

    // Floating-point array
    float floatArr[] = {64.5, 25.1, 12.3, 22.8, 11.0};
    int n2 = 5;

    // Sort and display integer array
    cout << "Sorted Integer Array: ";
    sortArray(intArr, n1);

    // Sort and display float array
    cout << "Sorted Float Array: ";
    cout << fixed << setprecision(1);
    sortArray(floatArr, n2);

    return 0;
}

/*
  Output:

  Sorted Integer Array: 11 12 22 25 64
  Sorted Float Array: 11.0 12.3 22.8 25.1 64.5
*/
