#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, base;
    cin >> n >> base;

    if (base < 2 || base > 9 || n < 0)
    {
        cout << "Invalid input" << endl;
        return 0;
    }

    stack<int> st;
    int temp = n;

    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    while (temp > 0)
    {
        st.push(temp % base);
        temp /= base;
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    cout << endl;
    return 0;
}
