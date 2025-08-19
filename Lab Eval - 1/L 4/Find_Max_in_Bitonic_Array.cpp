#include <iostream>
using namespace std;

int findMaxBitonic(int arr[], int n)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        if (low == high)
            return arr[low];

        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[mid + 1])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {9, 12, 15, 18, 14, 10, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxVal = findMaxBitonic(arr, n);
    cout << "Maximum element is " << maxVal << endl;

    return 0;
}
