#include <iostream>
#include <vector>
using namespace std;

void SecondSmallestElements(vector<int> &arr)
{
    int Min = INT_MAX;
    int SMin = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < Min)
        {
            Min = arr[i];
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != Min && arr[i] < SMin)
        {
            SMin = arr[i];
        }
    }

    cout << "Second Smallest element in the array is : " << SMin << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 7, 6, 5, 4, 3, 2, 2, -1};
    SecondSmallestElements(arr);
    return 0;
}