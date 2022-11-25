#include <iostream>
#include <string>
using namespace std;

#include <unordered_map>
string uniqueChar(string str)
{
    // Write your code here
    string result = "";
    unordered_map<char, int> meraMap;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (meraMap.count(str[i]) == 0)
        {
            meraMap[str[i]]++;
            result.push_back(str[i]);
        }
    }

    return result;
}

int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str);
}