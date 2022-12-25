#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
int countMinStepsToOne(int n)
{
    // Write your code here

    if (n <= 1)
    {
        return 0;
    }

    int a = 1 + countMinStepsToOne(n - 1);
    int c = INT_MAX;
    if (n % 2 == 0)
    {
        c = 1 + countMinStepsToOne(n / 2);
    }
    int b = INT_MAX;
    if (n % 3 == 0)
    {
        b = 1 + countMinStepsToOne(n / 3);
    }
    return min(a, min(b, c));
}

int main()
{
    int n;
    cin >> n;
    cout << countMinStepsToOne(n);
}