class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        map<int, map<int, int>> meraMap;

        for (int i = 0; i < nums.size(); i++)
        {
            meraMap[nums[i]].insert(make_pair(i, 1));
        }

        long long cnt = 0;
        for (auto i : meraMap)
        {
            // cout<<i.first<<" ";
            for (auto j : i.second)
            {
                int currind = j.first;
                if (meraMap[nums[currind]].find(currind) == meraMap[nums[currind]].end())
                {
                    continue;
                }
                // cout<<nums[currind]<<" ";
                if (meraMap[nums[currind]].size() == 0)
                {
                    meraMap.erase(nums[currind]);
                    continue;
                }
                cnt += nums[currind];
                if (currind == 0)
                {
                    if (meraMap[nums[currind + 1]].find(currind + 1) != meraMap[nums[currind + 1]].end())
                        meraMap[nums[currind + 1]].erase(currind + 1);
                }
                else if (currind == nums.size() - 1)
                {
                    if (meraMap[nums[currind - 1]].find(currind - 1) != meraMap[nums[currind - 1]].end())
                        meraMap[nums[currind - 1]].erase(currind - 1);
                }
                else
                {
                    cout << currind << " " << nums[currind + 1] << nums[currind - 1] << endl;
                    if (meraMap[nums[currind + 1]].find(currind + 1) != meraMap[nums[currind + 1]].end())
                        meraMap[nums[currind + 1]].erase(currind + 1);
                    if (meraMap[nums[currind - 1]].find(currind - 1) != meraMap[nums[currind - 1]].end())
                        meraMap[nums[currind - 1]].erase(currind - 1);
                }

                meraMap[nums[currind]].erase(currind);
            }
        }
        return cnt;
    }
};