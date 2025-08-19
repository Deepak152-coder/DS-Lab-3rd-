#include <iostream>
using namespace std;

int findMinBitonic(int arr[], int n)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        if (low == high)
            return arr[low];

        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return -1; 
}

int main()
{
    int arr[] = {9, 12, 15, 18, 14, 10, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int minVal = findMinBitonic(arr, n);
    cout << "Minimum element is " << minVal << endl;

    return 0;
}
