#include <iostream>
#include <unordered_set>
using namespace std;

void helper(int arr[], int n)
{
    unordered_set<int> seen;
    int current = 0, maximum = 0;

    for (int i = 0; i < n; i++)
    {
        if (seen.find(arr[i]) == seen.end())
        {
            seen.insert(arr[i]);
            current++;
        }
        else
        {
            current--;
        }

        if (current > maximum)
            maximum = current;
    }

    cout << "Maximum socks on table at the same time: " << maximum << endl;
}

int main()
{
    int n = 6;
    int *arr = new int[n]{1, 2, 1, 3, 2, 3};

    helper(arr, n);

    delete[] arr;
    return 0;
}
