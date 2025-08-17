#include <iostream>
using namespace std;

int selectionSort(int arr[], int n)
{
    int swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
    return swaps;
}

int main()
{
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int swaps = selectionSort(arr, n);
    cout << swaps << endl;

    return 0;
}
