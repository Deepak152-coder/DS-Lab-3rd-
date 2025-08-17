#include <iostream>
using namespace std;

int Helper(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return j + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {3, 6, 12, -10, 3, 3, 6, 34, 0, -109, 98, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int index = Helper(arr, n);

    if (index != -1)
    {
        cout << index << endl;
    }
    else
    {
        cout << "No repeating element found." << endl;
    }

    return 0;
}
