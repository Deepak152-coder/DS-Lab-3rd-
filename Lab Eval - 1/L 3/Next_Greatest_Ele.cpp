#include <iostream>
using namespace std;

void findNextGreaterAndPrint(int prices[], int n)
{
    int brr[n];
    int k = -1;
    int nextHigher[n];

    for (int i = 0; i < n; i++)
        nextHigher[i] = -1;

    for (int i = 0; i < n; i++)
    {
        while (k >= 0 && prices[i] > prices[brr[k]])
        {
            nextHigher[brr[k]] = prices[i];
            k--;
        }
        brr[++k] = i;
    }

    for (int i = 0; i < n; i++)
        cout << nextHigher[i] << " ";
    cout << endl;
}

int main()
{
    int prices[] = {100, 80, 120, 90, 150};
    int n = sizeof(prices) / sizeof(prices[0]);

    findNextGreaterAndPrint(prices, n);

    return 0;
}
