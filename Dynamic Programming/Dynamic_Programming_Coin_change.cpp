class Solution
{
public:
    int ways(vector<int> &arr, int ind, int target, vector<vector<int>> &memo)
    {
        if (ind == 0)
        {
            if (target % arr[0] == 0)
            {
                return target / arr[0];
            }
            return 1e9;
        }

        //  if(target == 0) return 0;
        // if(ind < 0) return -1;
        // if(target < arr[ind]) return -1;

        if (memo[ind][target] != -1)
        {
            return memo[ind][target];
        }
        int notpick = ways(arr, ind - 1, target, memo);
        int pick = INT_MAX;
        if (target >= arr[ind])
        {
            pick = 1 + ways(arr, ind, target - arr[ind], memo);
        }
        return memo[ind][target] = min(pick, notpick);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        //         vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,0));
        //         for(int i=0;i<=amount;i++){
        //             dp[0][i]=(i%coins[0]==0);

        //         }

        //         for(int i=1;i<coins.size();i++){
        //             for(int j=0;j<=amount;j++){
        //                 int notpick= dp[i-1][j];
        //                 int pick=0;
        //                 if((coins[i]<=j)){
        //                     pick=dp[i][j-coins[i]];
        //                 }
        //                 dp[i][j]=pick+notpick;
        //             }
        //         }
        //         return dp[coins.size()-1][amount];
        int n = coins.size();
        vector<vector<int>> memo(n + 1, vector<int>(amount + 1, -1));
        int ans = ways(coins, n - 1, amount, memo);
        if (ans >= 1e9)
        {
            return -1;
        }
        return ans;
    }
};