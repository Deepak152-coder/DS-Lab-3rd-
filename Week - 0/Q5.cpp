#include <iostream>
#include <vector>
#include <map>
using namespace std;

void Max_On_table(vector<int> &arr)
{
    map<int, int> mp;

    int OnTable = 0;
    int MaxOnTable = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] == 1)
        {
            OnTable++;
        }
        else if (mp[arr[i]] == 2)
        {
            OnTable--;
        }

        MaxOnTable = max(OnTable, MaxOnTable);
    }
    cout << "Max On Table is : " << MaxOnTable << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 2, 1, 3};
    Max_On_table(arr);
    return 0;
}