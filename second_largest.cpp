#include <iostream>
using namespace std;
#include <climits>

int main()
{

    // Write your code here
    int n;
    cin >> n;
    int max = INT_MIN;
    int max2 = max;
    int count = 1;
    int num;
    int i = 1;
    while (i <= n)
    {
        cin >> num;
        if (max < num)
        {
            max2 = max;
            max = num;
        }
        else if (max == num)
        {
            max2 = INT_MIN;
            max = num;
        }
        else
        {
            if (num > max2)
            {
                max2 = num;
            }
        }

        i++;
    }
    cout << max2;
}
