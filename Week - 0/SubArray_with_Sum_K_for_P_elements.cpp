#include <iostream>
using namespace std;

int helper(int arr[], int n, int k)
{
    int i = 0, j = 0;
    int currSum = 0;
    int count = 0;

    while (j < n)
    {
        currSum += arr[j];

        while (currSum > k && i <= j)
        {
            currSum -= arr[i];
            i++;
        }

        if (currSum == k)
        {
            count++;
        }

        j++;
    }

    return count;
}

int main()
{
    int arr[] = {1, 2, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = helper(arr, n, k);
    cout << "Number of subarrays with sum " << k << " : " << result << endl;

    return 0;
}
