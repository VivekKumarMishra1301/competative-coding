#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'Beautyful_fun' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING n as parameter.
 */

int Beautyful_fun(string n)
{
    long long int num = stoi(n);
    int sum = 0;
    while (num > 0)
    {
        long long int rem = num % 10;
        long long int k = (10 - rem);
        sum = sum + k;
        // cout << sum << " ";
        int dig = floor(log10(num) + 1);
        if (dig == 1)
        {
            sum = sum + (num - 1);

            return sum;
        }
        num += k;
        while (num % 10 == 0)
        {

            num = num / 10;
        }
    }

    return sum;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = Beautyful_fun(n);

    cout << result << "\n";

    // fout.close();

    return 0;
}
