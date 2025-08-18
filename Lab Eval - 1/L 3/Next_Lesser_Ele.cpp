#include <iostream>
using namespace std;

void nextLesserTemperature(int temp[], int n)
{
    int brr[n];
    int k = -1;
    int nextLesser[n];

    for (int i = 0; i < n; i++)
        nextLesser[i] = -1;

    for (int i = 0; i < n; i++)
    {
        while (k >= 0 && temp[i] < temp[brr[k]])
        {
            nextLesser[brr[k]] = temp[i];
            k--;
        }
        brr[++k] = i;
    }

    for (int i = 0; i < n; i++)
        cout << nextLesser[i] << " ";
    cout << endl;
}

int main()
{
    int temp[] = {30, 28, 35, 36, 33, 34};
    int n = sizeof(temp) / sizeof(temp[0]);

    nextLesserTemperature(temp, n);

    return 0;
}
