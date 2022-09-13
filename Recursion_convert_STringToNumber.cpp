#include <iostream>
int stringToNumber(char input[])
{
    // Write your code here
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        count++;
    }
    // if(input[0]=='\0'){
    //     return 0;
    // }
    if (count == 1)
    {
        int a = input[0] - 48;
        return a;
    }

    int mul = 1;
    for (int i = 0; i < count - 1; i++)
    {
        mul = mul * 10;
    }
    int b = input[0] - 48;
    int ans = mul * b;
    return ans + stringToNumber(input + 1);
}

using namespace std;

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
