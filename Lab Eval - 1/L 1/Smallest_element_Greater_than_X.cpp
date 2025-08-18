#include <iostream>
using namespace std;

int firstGreater(int arr[], int n, int target)
{
    int lo = 0, hi = n - 1;
    int ans = -1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
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
    int arr[] = {2, 4, 6, 8};
    int n = 4;
    int target = 5;

    int index = firstGreater(arr, n, target);
    cout << index;
    return 0;
}
