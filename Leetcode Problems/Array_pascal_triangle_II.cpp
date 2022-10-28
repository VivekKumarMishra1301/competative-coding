class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> store;
        vector<int> hold;
        hold.push_back(1);
        store.push_back(hold);
        for (int i = 2; i <= numRows; i++)
        {
            vector<int> arr(i);
            arr[0] = 1;
            arr[arr.size() - 1] = 1;
            if (i == 2)
            {
                for (int i = 0; i < arr.size(); i++)
                {
                    if (i < hold.size())
                    {
                        hold[i] = arr[i];
                    }
                    else
                    {
                        hold.push_back(arr[i]);
                    }
                }
                store.push_back(hold);
                continue;
            }
            for (int i = 0; i < hold.size() - 1; i++)
            {
                arr[i + 1] = hold[i] + hold[i + 1];
            }
            for (int i = 0; i < arr.size(); i++)
            {
                if (i < hold.size())
                {
                    hold[i] = arr[i];
                }
                else
                {
                    hold.push_back(arr[i]);
                }
            }
            store.push_back(hold);
        }
        return store;
    }
};