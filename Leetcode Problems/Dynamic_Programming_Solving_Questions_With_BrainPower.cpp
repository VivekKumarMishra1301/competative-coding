class Solution
{
public:
    long long pts(int ind, vector<vector<int>> &questions, vector<long long> &dp)
    {
        if (ind >= questions.size())
        {
            return 0;
        }

        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        long long pick = 0;
        // if(questions[ind][1]>=ind){
        pick = (long long)questions[ind][0] + (long long)pts(ind + questions[ind][1] + 1, questions, dp);
        // }else{
        // pick=questions[ind][0]+pts(ind+1,questions);
        // }

        long long notpick = pts(ind + 1, questions, dp);

        return dp[ind] = max(pick, notpick);
    }

    long long mostPoints(vector<vector<int>> &questions)
    {
        vector<long long> dp(questions.size() + 1, -1);
        return pts(0, questions, dp);
    }
};