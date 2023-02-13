class Solution
{
public:
    long long countFairPairs(vector<int> &arr, int lower, int upper)
    {

        long long int hold = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            int low = lower - arr[i];
            int up = upper - arr[i];
            hold += upper_bound(arr.begin() + (i + 1), arr.end(), up) - lower_bound(arr.begin() + (i + 1), arr.end(), low);
        }
        return hold;

        // //         unordered_map<int,int>meraMap;
        // //         for(auto i:nums){
        // //             meraMap[i]++;
        // //         }
        // //         long long hold=0;
        // //         for(int i=0;i<nums.size();i++){
        // //             int num=lower;
        // //             if(num==0){
        // //                 num++;
        // //             }

        // //             while(num<=upper){
        // //                 if(meraMap.count(num)!=0&&(nums[i]+num)>=lower&&(nums[i]+num)<=upper){
        // //                     hold+=meraMap[num];
        // //                 }
        // //                 num++;
        // //             }
        // //         }
        // //         return hold;
        //         sort(arr.begin(),arr.end());
        //         int n=arr.size();

        //         int i = 0;
        //     int k = 0;
        //     int l = 1;
        //     int m = 1;

        //     int flag2 = 0;
        //     int j = n - 1;

        //     while (i < j)
        //     {
        //         if ((arr[i] + arr[j]) < lower)
        //         {
        //             i++;
        //         }
        //         else if ((arr[i] + arr[j]) > upper)
        //         {
        //             j--;
        //         }
        //         else
        //         {
        //             int count = 1;
        //             int count2 = 1;
        //             int num = 0;
        //             int flag = 0;
        //             if (arr[i] == arr[j])
        //             {
        //                 num = j - i;
        //                 i = i + j;
        //             }
        //             else if (arr[i] == arr[i + 1] || arr[j] == arr[j - 1])
        //             {
        //                 flag = 1;
        //                 if (arr[i] == arr[i + 1])
        //                 {
        //                     // int count=0;
        //                     while (arr[i] == arr[i + 1])
        //                     {
        //                         i++;
        //                         count++;
        //                     }
        //                     i++;
        //                 }
        //                 if (arr[j] == arr[j - 1])
        //                 {
        //                     // int count2=0;
        //                     while (arr[j] == arr[j - 1])
        //                     {
        //                         count2++;
        //                         j--;
        //                     }
        //                     j--;
        //                 }
        //             }
        //             else
        //             {
        //                 k++;
        //                 i++;
        //                 j--;
        //             }
        //             if (flag == 1)
        //             {
        //                 k = k + count * count2;
        //             }
        //             // upper--;
        //             while (upper>lower)
        //             {
        //                 k = k + (upper-lower);
        //                 upper--;
        //             }
        //         }
        //     }
        //     return k;
    }
};