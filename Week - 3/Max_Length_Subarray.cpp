#include <iostream>
using namespace std;

int binarySearch(int suffixMin[], int low, int high, int x)
{
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (suffixMin[mid] <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int maxLengthSubarray(int arr[], int n)
{
    int suffixMin[n];
    suffixMin[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMin[i] = (arr[i] < suffixMin[i + 1]) ? arr[i] : suffixMin[i + 1];
    }

    int maxLen = 1;
    for (int i = 0; i < n; i++)
    {
        int j = binarySearch(suffixMin, i, n - 1, arr[i]);
        if (j != -1 && j >= i)
        {
            int len = j - i + 1;
            if (len > maxLen)
                maxLen = len;
        }
    }

    return maxLen;
}

int main()
{
    int arr[] = {-5, -1, 7, 5, 1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = maxLengthSubarray(arr, n);

    cout << ans << endl;
    return 0;
}
