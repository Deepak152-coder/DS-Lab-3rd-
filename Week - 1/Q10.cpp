#include <iostream>
#include <queue>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

bool isPalindrome(const string &input)
{
    queue<char> q;
    stack<char> s;

    for (char ch : input)
    {
        if (isalpha(ch))
        {
            char lower = tolower(ch);
            q.push(lower);
            s.push(lower);
        }
    }

    while (!q.empty())
    {
        if (q.front() != s.top())
        {
            return false;
        }
        q.pop();
        s.pop();
    }

    return true;
}

int main()
{
    string line;
    cout << "Enter a line: ";
    getline(cin, line);

    if (isPalindrome(line))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}
