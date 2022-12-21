#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void bhagdena()
{
    int size, k;
    long long int chacha, guda = 1;
    ;
    cin >> size >> k;
    for (int i = 0; i < size; i++)
    {
        cin >> chacha;
        guda = (guda * chacha) % k;
    }
    if (guda == 0)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {

        bhagdena();
    }
    return 0;
}
