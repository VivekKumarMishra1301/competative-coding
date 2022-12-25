void printSubset(vector<int> &arr, vector<int> &hold, int n, int ind)
{
    if (ind >= n)
    {
        return;
    }
    printSubset(arr, hold, n, ind + 1);
    hold.push_back(arr[ind]);
    for (int i = 0; i < hold.size(); i++)
    {
        cout << hold[i] << " ";
    }
    cout << endl;
    printSubset(arr, hold, n, ind + 1);
    hold.pop_back();
}

void printAllSubsets(int n, vector<int> &arr)
{
    // Write your code here
    vector<int> hold;
    printSubset(arr, hold, n, 0);
}