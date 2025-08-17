#include <iostream>
using namespace std;

int helper(int arr[], int n, int K)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == K)
            {
                count++;
            }
        }
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
// Update it for Optimal soluton using prefix sum and hash map