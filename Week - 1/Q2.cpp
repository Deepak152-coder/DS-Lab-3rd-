#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int findNextGreaterDistance(vector<int> &arr, int element)
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

    if (index == -1 || index == n - 1)
        return -1;

    stack<int> st;
    for (int i = n - 1; i > index; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        st.push(arr[i]);

        if (arr[i] > element)
        {
            return i - index;
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

    int result = findNextGreaterDistance(arr, element);

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
