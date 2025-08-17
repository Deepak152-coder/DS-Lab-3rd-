#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int k)
{
    int lo = 0, hi = n - 1;
    while (lo <= hi && k >= arr[lo] && k <= arr[hi])
    {
        if (lo == hi)
        {
            if (arr[lo] == k)
                return lo; 
            return -1;
        }

        int pos = lo + ((k - arr[lo]) * (hi - lo)) / (arr[hi] - arr[lo]);

        if (arr[pos] == k)
            return pos;
        if (arr[pos] < k)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 60;

    int index = interpolationSearch(arr, n, k);

    if (index != -1)
        cout << "Element found at position: " << index + 1 << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
