#include <iostream>
using namespace std;

#include <bits/stdc++.h>
int ways(int arr[], int ind, int target, vector<vector<int>> &memo)
{
    if (ind == 0)
    {
        return target % arr[0] == 0;
    }

    if (memo[ind][target] != -1)
    {
        return memo[ind][target];
    }
    int notpick = ways(arr, ind - 1, target, memo);
    int pick = 0;
    if (target >= arr[ind])
    {
        pick = ways(arr, ind, target - arr[ind], memo);
    }
    return memo[ind][target] = pick + notpick;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    // Write your code here
    vector<vector<int>> memo(numDenominations + 1, vector<int>(value + 1, -1));
    return ways(denominations, numDenominations - 1, value, memo);
}

int main()
{

    int numDenominations;
    cin >> numDenominations;

    int *denominations = new int[numDenominations];

    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }

    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);

    delete[] denominations;
}