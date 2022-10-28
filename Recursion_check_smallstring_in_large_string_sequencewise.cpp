#include <iostream>
using namespace std;
bool checksequenece(char large[], char *small)
{
    if (small[0] == '\0')
    {
        return true;
    }
    int count = 0;
    int i = 0;
    for (i = 0; large[i] != '\0'; i++)
    {
        if (large[i] == small[0])
        {
            count++;
            break;
        }
        count++;
    }
    if (large[i] != '\0')
    {
        return checksequenece(large + count, small + 1);
    }
    else
    {
        return false;
    }
}

int main()
{
    char large[10000];
    char small[10000];
    cin >> large;
    cin >> small;
    bool x = checksequenece(large, small);

    if (x)
        cout << "true";
    else
        cout << "false";
}
