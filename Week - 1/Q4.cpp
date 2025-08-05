#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

int firstNonRepeatingCharIndex(string s)
{
    unordered_map<char, int> freq;
    queue<pair<char, int>> q;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        freq[ch]++;
        q.push({ch, i});

        while (!q.empty() && freq[q.front().first] > 1)
        {
            q.pop();
        }
    }

    if (q.empty())
        return -1;
    return q.front().second;
}

int main()
{
    string s;
    getline(cin, s);

    int index = firstNonRepeatingCharIndex(s);

    if (index == -1)
    {
        cout << "Character: None" << endl;
        cout << "Index: -1" << endl;
    }
    else
    {
        cout << "Character: " << s[index] << endl;
        cout << "Index: " << index << endl;
    }

    return 0;
}
