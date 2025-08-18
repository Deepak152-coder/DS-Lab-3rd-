#include <iostream>
using namespace std;

void sortArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

void findMaxGuests(int entry[], int exit[], int n)
{
    sortArray(entry, n);
    sortArray(exit, n);

    int i = 0, j = 0;
    int guests = 0, maxGuests = 0, time = 0;

    while (i < n && j < n)
    {
        if (entry[i] <= exit[j])
        {
            guests++;
            if (guests > maxGuests)
            {
                maxGuests = guests;
                time = entry[i];
            }
            i++;
        }
        else
        {
            guests--;
            j++;
        }
    }

    cout << maxGuests << " " << time;
}

int main()
{
    int entry[] = {1, 2, 9, 5, 5};
    int exit[] = {4, 5, 12, 9, 12};
    int n = 5;

    findMaxGuests(entry, exit, n);

    return 0;
}
