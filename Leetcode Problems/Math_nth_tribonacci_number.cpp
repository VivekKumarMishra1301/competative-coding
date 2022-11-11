class Solution {
public:
    int tribo(int n, vector<int>& dp) {
        if (n == 0) {
            dp[n] = 0;
            return dp[n];
        }
        if (n == 1 || n == 2) {
            dp[n] = 1;
            return dp[n];
        }
        if (dp[n] != 0) {
            return dp[n];
        }
        dp[n] = tribo(n - 1, dp) + tribo(n - 2, dp) + tribo(n - 3, dp);
        return dp[n];

    }


    int tribonacci(int n) {
        vector<int>dp(n + 1, 0);
        int res = tribo(n, dp);
        return res;
    }
};