
#include <bits/stdc++.h>
// int prof(int *w,int*p,int ind,int wt,vector<vector<int>>&memo){
//   if(ind==0){
//     if(wt>=w[0]){
//       return p[0];
//     }
//     return 0;
//   }

//   if(memo[ind][wt]!=-1){
//     return memo[ind][wt];
//   }
// int notpick=prof(w,p,ind-1,wt,memo);
// int pick=INT_MIN;
// if(w[ind]<=wt){
//   pick=p[ind]+prof(w,p,ind-1,wt-w[ind],memo);
// }
// return memo[ind][wt]=max(pick,notpick);
// }

int knapsack(int *weight, int *value, int n, int maxWeight)
{
    // Write your code here
    // vector<vector<int>>memo(n+1,vector<int>(maxWeight+1,-1));
    // return prof(weight,value,n-1,maxWeight,memo);
    vector<int> prev(maxWeight + 1, 0);
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        prev[w] = value[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            int notpick = prev[w];
            int pick = INT_MIN;
            if (weight[ind] <= w)
            {
                pick = value[ind] + prev[w - weight[ind]];
            }
            prev[w] = max(pick, notpick);
        }
    }
    return prev[maxWeight];
}