class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>hold;
        if (rowIndex == 0) {
            hold.push_back(1);
            return hold;
        }
        for (int i = 1;i <= rowIndex;i++) {
            vector<int>arr(i + 1);
            arr[0] = 1;
            arr[arr.size() - 1] = 1;
            if (i == 1)
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
                if (i == rowIndex) {
                    return hold;
                }
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


        }
        return hold;



    }
};