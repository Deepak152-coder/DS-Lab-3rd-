#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void findMinDiffPairs(int arr[], int n)
{
    bubbleSort(arr, n);

    int minDiff = abs(arr[1] - arr[0]);
    for (int i = 1; i < n - 1; i++)
    {
        int diff = abs(arr[i + 1] - arr[i]);
        if (diff < minDiff)
        {
            minDiff = diff;
        }
    }

    cout << "Smallest pairs with difference " << minDiff << ": ";
    for (int i = 0; i < n - 1; i++)
    {
        int diff = abs(arr[i + 1] - arr[i]);
        if (diff == minDiff)
        {
            cout << "{" << arr[i] << "," << arr[i + 1] << "} ";
        }
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 5, 4, 89, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    findMinDiffPairs(arr, n);

    return 0;
}
