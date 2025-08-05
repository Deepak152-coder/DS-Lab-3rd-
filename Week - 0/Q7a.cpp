#include <iostream>
#include <vector>
using namespace std;

int countSubarraysWithSumK(vector<int> &arr, int k)
{
    int start = 0, end = 0;
    int sum = 0, count = 0;
    int n = arr.size();

    while (end < n)
    {
        sum += arr[end];

        while (sum > k && start <= end)
        {
            sum -= arr[start];
            start++;
        }

        if (sum == k)
        {
            count++;
        }

        end++;
    }

    return count;
}

int main()
{
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements (positive integers only): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    int result = countSubarraysWithSumK(arr, k);
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;

    return 0;
}
