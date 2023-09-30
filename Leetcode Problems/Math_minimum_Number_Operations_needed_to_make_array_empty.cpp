class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto i : nums)
        {
            mp[i]++;
        }

        int cnt = 0;
        for (auto i : mp)
        {
            cout << i.first << " " << i.second << endl;
            if (i.second % 3 == 0)
            {
                cnt += (i.second / 3);
            }
            else if (i.second % 3 == 2)
            {
                cnt += (i.second / 3);
                cnt++;
            }
            else if (i.second % 3 == 1 && i.second != 1)
            {
                cnt += (i.second / 3);
                cnt++;
            }
            else if (i.second % 2 == 0)
            {
                cnt += (i.second / 2);
            }
            else
            {
                return -1;
            }
        }
        return cnt;
    }
};