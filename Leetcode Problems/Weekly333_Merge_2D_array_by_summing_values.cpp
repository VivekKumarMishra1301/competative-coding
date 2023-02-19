class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        unordered_map<int, vector<int>> meraMap;
        set<int> s;
        priority_queue<int, vector<int>, greater<int>> d;
        for (int i = 0; i < nums1.size(); i++)
        {
            meraMap[nums1[i][0]].push_back(nums1[i][1]);
            // d.push(nums1[i][0]);
            s.insert(nums1[i][0]);
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            meraMap[nums2[i][0]].push_back(nums2[i][1]);
            // d.push(nums2[i][0]);
            s.insert(nums2[i][0]);
        }

        vector<vector<int>> hold;
        for (auto i : s)
        {
            vector<int> k = meraMap[i];
            int t = i;
            // d.pop();
            int s = accumulate(k.begin(), k.end(), 0);
            hold.push_back({t, s});
        }
        return hold;
    }
};