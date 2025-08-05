#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countSubarraysWithSumK(vector<int> &arr, int k)
{
    unordered_map<int, int> prefixSumCount;
    int sum = 0, count = 0;

    prefixSumCount[0] = 1;

    for (int num : arr)
    {
        sum += num;
        if (prefixSumCount.find(sum - k) != prefixSumCount.end())
        {
            count += prefixSumCount[sum - k];
        }
        prefixSumCount[sum]++;
    }

    return count;
}

int main()
{
    int n, k;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;

    int result = countSubarraysWithSumK(arr, k);
    cout << result << endl;

    return 0;
}
