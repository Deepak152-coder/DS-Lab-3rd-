#include <iostream>
using namespace std;

void helper(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            cout << arr[i] << " ";
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
            cout << arr[i] << " ";
    }
}

int main()
{
    int n = 8;
    int *arr = new int[n]{2, 8, 3, 6, 7, 9, 5, 4};

    helper(arr, n);

    delete[] arr;
    return 0;
}
