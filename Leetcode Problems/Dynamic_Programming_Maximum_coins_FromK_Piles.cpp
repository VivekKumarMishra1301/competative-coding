class Solution
{
public:
    //     int memo(vector<vector<int>>& piles, int k,int ind,vector<vector<int>>&dp){
    //         if(ind>=piles.size()){
    //             return 0;;
    //         }
    //          if(k < 0)   return INT_MIN;
    //         if(ind < 0)    return 0;
    //         if(dp[ind][k]!=-1){
    //             return dp[ind][k];
    //         }
    //         int maxi=0;
    //         maxi=max(maxi,memo(piles,k,ind+1,dp));
    //         for(int j=0;j<piles[ind].size();j++){
    //             if(j+ind<=k){
    //                 maxi=max(maxi,piles[ind][j]+memo(piles,k-(j+1),ind+1,dp));
    //             }
    //         }
    //         return dp[ind][k]=maxi;
    //     }

    //     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    //         for(int i=0;i<piles.size();i++){
    //             for(int j=1;j<piles[0].size();j++){
    //                 piles[i][j]=piles[i][j]+piles[i][j-1];
    //             }
    //         }

    //         vector<vector<int>>dp(piles.size()+1,vector<int>(k+1,-1));
    //         return memo(piles,k,0,dp);

    //     }
    int dp[1001][2001]; // Dp array For Memoization.
    int solve(vector<vector<int>> &v, int index, int coin)
    {
        if (index >= v.size() || coin == 0) // Base Condition
            return 0;
        if (dp[index][coin] != -1) // Check wheather It is Already Calculated Or not.
            return dp[index][coin];

        /* Our 1st choice :- We not take any Coin from that pile*/
        int ans = solve(v, index + 1, coin); // Just Call function for next Pile.

        /*Otherwise we can take Coins from that Pile.*/
        int loop = v[index].size() - 1;
        int sum = 0;

        for (int j = 0; j <= min(coin - 1, loop); j++) //
        {
            sum = sum + v[index][j];
            ans = max(ans, sum + solve(v, index + 1, coin - (j + 1)));

            /*Above we Pass coin-(j+1). Because till j'th index we have taken j+1 coin from that pile.*/
        }

        return dp[index][coin] = ans;
    }
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        memset(dp, -1, sizeof(dp));
        return solve(piles, 0, k);
    }
};