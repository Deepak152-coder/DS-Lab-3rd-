#include <iostream>
using namespace std;

int Helper(int arr[], int n)
{
    int d = (arr[n - 1] - arr[0]) / n;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] + d != arr[i + 1])
        {
            return arr[i] + d;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int missing = Helper(arr, n);

    if (missing != -1)
        cout << "Missing element: " << missing << endl;
    else
        cout << "No element is missing." << endl;

    return 0;
}
