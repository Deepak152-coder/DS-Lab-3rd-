#include <iostream>
#include <vector>
using namespace std;

void LeftRotateByOne(vector<int> &arr)
{
    int temp = arr[0];
    for (int i = 0; i < arr.size() - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[arr.size() - 1] = temp;

    cout << "Elements after left Rotate By One is : " << endl;
    for (auto x : arr)
    {
        cout << x << " ";
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    LeftRotateByOne(arr);
    return 0;
}