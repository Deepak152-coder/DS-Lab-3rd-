#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int x)
{
    int lo = 0, hi = n - 1, ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            hi = mid - 1;
        }
        else if (x < arr[mid])
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}

int lastOcc(int arr[], int n, int x)
{
    int lo = 0, hi = n - 1, ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            lo = mid + 1;
        }
        else if (x < arr[mid])
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 3, 3, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;

    int f = firstOcc(arr, n, x);
    int l = lastOcc(arr, n, x);

    if (f == -1)
        cout << x << " not found." << endl;
    else
        cout << "First Position: " << (f + 1) << endl
             << "Last Position: " << (l + 1) << endl;

    return 0;
}
