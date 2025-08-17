#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void findTwoSum(int arr[], int n, int target)
{
    bubbleSort(arr, n);

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == target)
        {
            cout << "[" << i + 1 << ", " << j + 1 << "]" << endl;
            return;
        }
        else if (sum < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    cout << "No such pair" << endl;
}

int main()
{
    int arr[] = {2, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    findTwoSum(arr, n, target);

    return 0;
}
