int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n)
{
    // Write your code here.

    int ind = -1;
    vector<int> hold;
    int fuel = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        hold.push_back(gas[i] - cost[i]);
        fuel += hold[i];
        // cout<<hold[i]<<" ";
    }
    if (fuel < 0)
    {
        return -1;
    }
    int sum = 0;
    ind = 0;
    for (int i = 0; i < hold.size(); i++)
    {
        if (sum < 0)
        {
            sum = hold[i];
            ind = i;
            continue;
        }
        sum += hold[i];
    }

    return ind;
}
// check solution of leetcode and coding ninjas
