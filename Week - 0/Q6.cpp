#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int *arr = new int[n];

    cout << "Enter elements in the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Elements in the array are : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}