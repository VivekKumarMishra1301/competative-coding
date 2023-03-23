class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        priority_queue<pair<int, int>> pq;
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                pq.push({cnt, nums[i - 1]});
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        pq.push({cnt, nums[nums.size() - 1]});
        vector<int> hold;
        while (k--)
        {
            pair<int, int> l = pq.top();
            hold.push_back(l.second);
            pq.pop();
        }
        return hold;
    }
};