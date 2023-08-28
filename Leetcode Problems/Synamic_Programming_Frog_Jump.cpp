class Solution
{
public:
    map<pair<int, int>, bool> mp;
    map<int, int> pos;
    bool memo(int ind, int k, vector<int> &stones)
    {
        cout << "status"
             << ":" << ind << " " << k;
        if (ind > stones[stones.size() - 1])
        {
            return false;
        }
        if (ind == stones[stones.size() - 1])
        {
            return mp[{ind, k}] = true;
        }

        if (mp.find({ind, k}) != mp.end())
        {
            return mp[{ind, k}];
        }
        bool ans = false;
        // if(ind!=0){

        if (pos.find(ind + k - 1) != pos.end())
        {
            cout << " first";
            if (k - 1 != 0)
                ans = ans || memo(ind + k - 1, k - 1, stones);
        }
        // }

        if (pos.find(ind + k) != pos.end())
        {
            cout << " sec";
            if (k != 0)
                ans = ans || memo(ind + k, k, stones);
        }

        if (pos.find(ind + k + 1) != pos.end())
        {
            cout << " l";
            if (k + 1 != 0)
                ans = ans || memo(ind + k + 1, k + 1, stones);
        }
        return mp[{ind, k}] = ans;
    }

    bool canCross(vector<int> &stones)
    {
        if (stones[0] != 0 || stones[1] != 1)
        {
            return false;
        }
        for (auto i : stones)
        {
            pos[i]++;
        }
        pos.erase(0);
        bool ans = memo(0, 0, stones);
        return ans;
    }
};