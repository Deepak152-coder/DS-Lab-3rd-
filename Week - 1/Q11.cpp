#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string extractAndReverse(const string &str)
{
    size_t s1_start = str.find('X');
    size_t s1_end = str.find('Y', s1_start + 1);

    if (s1_start == string::npos || s1_end == string::npos)
        return "";

    size_t s2_start = str.find('Y', s1_end + 1);
    size_t s2_end = str.find('X', s2_start + 1);

    if (s2_start == string::npos || s2_end == string::npos)
        return "";

    size_t extract_start = s1_end + 1;
    size_t extract_end = s2_start;

    if (extract_start >= extract_end)
        return "";

    string result = str.substr(extract_start, extract_end - extract_start);
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string input;
    getline(cin, input);

    string output = extractAndReverse(input);
    cout << output << endl;

    return 0;
}
