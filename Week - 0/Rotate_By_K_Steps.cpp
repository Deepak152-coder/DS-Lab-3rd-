#include <iostream>
using namespace std;

void reverse(int arr[], int i, int j)
{
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void leftRotate(int arr[], int n, int d)
{
    d = d % n;
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 3;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    leftRotate(arr, n, d);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
