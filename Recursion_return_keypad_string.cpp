#include <iostream>
#include <string>
#include <string>
using namespace std;

int keypad(int num, string output[])
{
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string s1;
    if (num == 0 || num == 1)
    {
        output[0] = "";
        return 1;
    }
    int temp = num % 10;
    num = num / 10;
    int smallopSize = keypad(num, output);
    switch (temp)
    {
    case 2:
        s1 = "abc";
        break;
    case 3:
        s1 = "def";
        break;
    case 4:
        s1 = "ghi";
        break;
    case 5:
        s1 = "jkl";
        break;
    case 6:
        s1 = "mno";
        break;
    case 7:
        s1 = "pqrs";
        break;
    case 8:
        s1 = "tuv";
        break;
    case 9:
        s1 = "wxyz";
        break;
    }
    int ansSize = smallopSize * (s1.size());
    string arr[ansSize];
    int k = 0;
    for (int i = 0; i < smallopSize; i++)
    {
        for (int j = 0; j < s1.size(); j++)
        {
            arr[k] = output[i] + s1[j];

            k++;
        }
    }

    for (int i = 0; i < ansSize; i++)
    {
        output[i] = arr[i];
    }
    return s1.size() * smallopSize;
}

using namespace std;

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
