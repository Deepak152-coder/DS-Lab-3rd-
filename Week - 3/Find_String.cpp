#include <iostream>
using namespace std;

int findString(string arr[], int n, string x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return 0;
}

int main()
{
    string arr[] = {"Hi", "Folks", "ide", "for", "practice"};
    int n = sizeof(arr) / sizeof(arr[0]);
    string x = "ide";

    int index = findString(arr, n, x);
    cout << index << endl;

    return 0;
}
