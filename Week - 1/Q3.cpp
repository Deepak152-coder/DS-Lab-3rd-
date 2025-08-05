#include <iostream>
#include <vector>
using namespace std;

int findNextGreaterCircular(vector<int> &arr, int element)
{
    int n = arr.size();
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        return -1;

    for (int i = 1; i < n; i++)
    {
        int nextIndex = (index + i) % n;
        if (arr[nextIndex] > element)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n, element;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> element;

    int result = findNextGreaterCircular(arr, element);

    if (result == -1)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}
