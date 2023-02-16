class Solution
{
public:
    void combine(int ind, vector<int> &cand, int target, vector<int> &hold1, vector<vector<int>> &hold)
    {
        if (target == 0)
        {
            hold.push_back(hold1);
            return;
        }

        for (int i = ind; i < cand.size(); i++)
        {
            if (target < cand[i])
            {
                break;
            }
            if (i != ind && cand[i] == cand[i - 1])
            {
                continue;
            }
            hold1.push_back(cand[i]);
            combine(i + 1, cand, target - cand[i], hold1, hold);
            hold1.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> hold1;
        vector<vector<int>> hold;
        combine(0, candidates, target, hold1, hold);
        return hold;
    }
};