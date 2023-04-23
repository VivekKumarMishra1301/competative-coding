class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        vector<int> hold;
        int st = 0;
        int en = 0;
        map<int, int> meraMap;
        while (en < nums.size())
        {
            if (nums[en] <= 0)
            {
                meraMap[nums[en]]++;
            }

            if (en - st + 1 == k)
            {
                bool flag = false;
                int cnt = 0;
                for (auto i : meraMap)
                {
                    cnt += i.second;
                    if (cnt >= x)
                    {
                        hold.push_back(i.first);
                        meraMap[nums[st++]]--;
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    hold.push_back(0);
                    meraMap[nums[st++]]--;
                }
            }

            en++;
        }
        return hold;
    }
};