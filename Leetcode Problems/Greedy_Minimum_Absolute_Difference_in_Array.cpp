class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] < mini)
            {
                mini = arr[i] - arr[i - 1];
            }
        }

        vector<vector<int>> hold;

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] == mini)
            {
                hold.push_back({arr[i - 1], arr[i]});
            }
        }
        return hold;
    }
};