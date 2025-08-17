#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void helper(int *arr, int n)
{
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    cout << "Array elements : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int *arr = new int[n];

    helper(arr, n);

    delete[] arr;
    return 0;
}
