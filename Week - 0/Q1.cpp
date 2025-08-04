#include <iostream>
#include <vector>
#include <map>
using namespace std;

void Freq(vector<int> arr)
{
    map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }
    cout << "Frequency of Each Element is : " << endl;

    for (auto x : mp)
    {
        cout << x.first << " occurs " << x.second << " times " << endl;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 5, 2, 9, 7, 3, 5};
    Freq(arr);
    return 0;
}