class Solution
{
public:
    int larg(vector<int> &obs, int num)
    {
        return upper_bound(begin(obs), end(obs), num) - begin(obs);
    }

    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacle)
    {
        map<int, int> meraMap;
        vector<int> hold;
        vector<int> obs;
        for (int i = 0; i < obstacle.size(); i++)
        {
            if (obs.size() == 0 || obstacle[i] >= obs.back())
            {
                obs.push_back(obstacle[i]);
                hold.push_back(obs.size());
            }
            else
            {
                int ind = larg(obs, obstacle[i]);
                obs[ind] = obstacle[i];
                hold.push_back(ind + 1);
            }
        }
        return hold;
    }
};