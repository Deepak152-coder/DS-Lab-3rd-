#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expr)
{
    stack<char> st;

    for (char ch : expr)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.empty())
                return false;
            char top = st.top();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{'))
            {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    string s;
    cout << "Enter expression: ";
    getline(cin, s);

    if (isBalanced(s))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
