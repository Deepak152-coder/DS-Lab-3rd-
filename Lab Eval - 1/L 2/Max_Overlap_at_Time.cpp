#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
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

int maxOverlap(int lines[][2], int n)
{
    int start[100], end[100];

    for (int i = 0; i < n; i++)
    {
        start[i] = lines[i][0];
        end[i] = lines[i][1];
    }

    // sort using bubble sort
    bubbleSort(start, n);
    bubbleSort(end, n);

    int i = 0, j = 0;
    int count = 0, maxCount = 0;

    while (i < n && j < n)
    {
        if (start[i] <= end[j])
        {
            count++;
            if (count > maxCount)
                maxCount = count;
            i++;
        }
        else
        {
            count--;
            j++;
        }
    }
    return maxCount;
}

int main()
{
    int n = 4;
    int lines[4][2] = {{1, 3}, {2, 3}, {1, 2}, {4, 4}};
    cout << maxOverlap(lines, n);
    return 0;
}
