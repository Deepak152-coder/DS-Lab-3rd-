#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void moveNthFront(queue<int> &q, int n)
{
    if (n <= 0 || n > q.size())
        return;

    vector<int> v;

    while (!q.empty())
    {
        v.push_back(q.front());
        q.pop();
    }

    int target = v[n - 1];
    v.erase(v.begin() + n - 1);
    q.push(target);

    for (int x : v)
    {
        q.push(x);
    }
}

int main()
{
    queue<int> q;
    q.push(5);
    q.push(11);
    q.push(34);
    q.push(67);
    q.push(43);
    q.push(55);

    int n = 3;

    moveNthFront(q, n);

    cout << "Output queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
