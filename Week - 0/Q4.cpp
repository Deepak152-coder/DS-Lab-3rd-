#include <iostream>
#include <vector>
using namespace std;

void Printing_Even_Odd(vector<int> &arr)
{
    cout << "Printing Even then Odd : ";
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0)
        {
            cout << arr[i] << " ";
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 != 0)
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 7, 6, 5, 4, 3, 2, 2, -1};
    Printing_Even_Odd(arr);
    return 0;
}