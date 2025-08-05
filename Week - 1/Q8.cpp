#include <iostream>
#include <queue>
#include <string>
using namespace std;

string compressString(const string &input)
{
    queue<char> q;
    for (char ch : input)
    {
        if (ch != ' ')
            q.push(ch);
    }

    string result = "";

    while (!q.empty())
    {
        char current = q.front();
        int count = 0;

        while (!q.empty() && q.front() == current)
        {
            count++;
            q.pop();
        }

        result += current + to_string(count);
    }

    return result;
}

int main()
{
    string input;
    getline(cin, input);

    string compressed = compressString(input);
    cout << compressed << endl;

    return 0;
}
