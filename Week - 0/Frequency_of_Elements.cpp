#include <iostream>
using namespace std;

void helper(int arr[], int n)
{
    int maxElement = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }

    int freq[maxElement + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    cout << "Frequency of elements in the array:\n";
    for (int i = 0; i <= maxElement; i++)
    {
        if (freq[i] != 0)
        {
            cout << "Element " << i << " occurs " << freq[i] << " times" << endl;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    helper(arr, n);
    return 0;
}
