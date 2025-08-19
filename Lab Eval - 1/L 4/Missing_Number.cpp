#include <iostream>
using namespace std;

void printMissingSlots(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int index = arr[i];
        if (index < 0)
            index = -index;
        index = index - 1;
        if (arr[index] > 0)
            arr[index] = -arr[index];
    }

    int count = 0;
    cout << "Missing slots: ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            cout << (i + 1) << " ";
            count++;
        }
    }
    cout << "\nTotal missing slots: " << count << endl;
}

int main()
{
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printMissingSlots(arr, n);

    return 0;
}
