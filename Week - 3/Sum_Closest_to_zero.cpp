#include <iostream>
#include <climits>
using namespace std;

int Helper(int arr[], int n, int k)
{
    int Csum = arr[0] + arr[1];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if (abs(sum - k) < abs(Csum - k))
            {
                Csum = sum;
            }
        }
    }
    return Csum;
}

int main()
{
    int arr[] = {-5, -50, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 50;

    int result = Helper(arr, n, k);

    cout << result << endl;

    return 0;
}
