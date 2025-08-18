#include <iostream>
using namespace std;

int searchInsert(int arr[], int n, int target)
{
    int lo = 0, hi = n - 1;
    int ans = n;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] >= target)
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
    int arr[] = {10, 20, 30, 50};
    int n = 4;
    int target = 25;
    cout << searchInsert(arr, n, target);
    return 0;
}
