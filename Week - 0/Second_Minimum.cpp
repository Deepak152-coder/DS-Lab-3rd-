#include <iostream>
using namespace std;

void helper(int arr[], int n)
{
    int fmin = INT_MAX;
    int smin = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < fmin)
        {
            smin = fmin;
            fmin = arr[i];
        }
        else if (arr[i] != fmin && arr[i] < smin)
        {
            smin = arr[i];
        }
    }

    cout << "First Minimum is : " << fmin << endl;
    cout << "Second Minimum is : " << smin << endl;
}

int main()
{
    int arr[] = {0, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    helper(arr, n);
    return 0;
}
