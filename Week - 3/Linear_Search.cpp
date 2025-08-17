#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;

    int index = linearSearch(arr, n, x);

    if (index != -1)
        cout << "Present at position " << index + 1 << endl;
    else
        cout << "Not present" << endl;

    return 0;
}
