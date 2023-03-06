class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0;
        int cnt=1;
        while(i<arr.size()){
            if(arr[i]!=cnt){
                k--;
                if(!k){
                    return cnt;
                }
                cnt++;
                continue;
            }
            cnt++;
            i++;
        }
        if(k){
            return cnt+k-1;
        }
        return -1;
    }
};