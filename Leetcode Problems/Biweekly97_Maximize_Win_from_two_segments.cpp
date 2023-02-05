class Solution
{
public:
    int maximizeWin(vector<int> &pP, int k)
    {

        int n = pP.size();
        int st = 0;
        int hold = 0;
        vector<int> dp(n);
        for (int en = 0; en < n; en++)
        {
            while (pP[en] - pP[st] > k)
            {
                st++;
            }

            int curr = en - st + 1;
            if (st > 0)
            {
                curr += dp[st - 1];
            }

            hold = max(hold, curr);
            int first = 0;
            if (en > 0)
            {
                first = dp[en - 1];
            }

            dp[en] = max(first, en - st + 1);
        }
        return hold;
        //         vector<int>hold;
        //         unordered_map<int,int>meraMap;
        //         for(auto i:prizePositions){
        //             meraMap[i]++;
        //         }
        //         hold.push_back(prizePositions[0]);
        //         unordered_map<int,int>pos;
        //         pos[prizePositions[0]]=0;
        //         for(int i=1;i<prizePositions.size();i++){
        //             if(prizePositions[i]!=prizePositions[i-1]){
        //                 hold.push_back(prizePositions[i]);
        //                  pos[prizePositions[i]]=hold.size()-1;
        //                 // cout<<hold[hold.size()-1]<<" ";
        //             }
        //         }
        //         int end=hold.size()-1;
        //         if(k>=hold[end]){
        //             return prizePositions.size();
        //         }
        //         vector<int>num;
        //         unordered_map<int,int>get;
        //         for(int i=0;i<hold.size();i++){
        //             if(meraMap.count(hold[i]+k)!=0){
        //                 int st=i;
        //                 int end=pos[hold[i]+k];
        //                 // cout<<hold[st]<<":"<<hold[end]<<":";
        //                 // cout<<hold[i];
        //                 cout<<end<<":";
        //                 int nums=0;
        //                 if(get.count(i)!=0){
        //                     st++;
        //                 }else{
        //                     get[end]++;
        //                     // get[st]++;
        //                 }
        //                 for(int j=st;j<=end;j++){
        //                     // cout<<meraMap[hold[j]];
        //                     nums+=meraMap[hold[j]];
        //                 }
        //                 // cout<<" ";
        //                 num.push_back(nums);
        //             }
        //         }
        //         sort(num.begin(),num.end());
        //         if(num.size()==0){
        //             return 0;
        //         }
        // //         if(hold.size()>=2){

        // //         }

        //         if(num.size()==1){
        //             return num[num.size()-1];
        //         }else{
        //             int in=num.size()-1;
        //             return num[in]+num[in-1];
        //         }
        //         // for(int i=0;i<prizePositions.size();i++){
        //         //     if(meraMap.count(prizePositions[i])==0){
        //         //         meraMap[prizePositions[i]]=i;
        //         //     }
        //         // }
        //         // // if(k==0){
        //         // //     return meraMap.size();
        //         // // }
        //         // vector<int>hold1;
        //         // for(int i=1;i<hold.size();i++){
        //         //     if((hold[i]-hold[i-1])==k){
        //         //          int num=0;
        //         //         for(int j=meraMap[hold[i-1]];prizePositions[j]<=hold[i];j++){
        //         //             num++;
        //         //         }
        //         //         hold1.push_back(num);
        //         //     }
        //         // }

        //         // return num;
    }
};