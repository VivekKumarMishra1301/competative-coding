class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        int i = 0;
        while (!pq.empty())
        {
            nums[i++] = pq.top();
            pq.pop();
        }
        return nums;
    }
};



int cnt=0;

  if(xox%2==0)
         {
             int diff=yoy-xox;
             if(diff%2==0){
                cnt+=diff/2;
             }else{
                cnt+=diff/2;
                cnt++;
             }
         }
         else if(xox==3||xox==9)
         {
             
             xox += 3;
             cnt++;
             int diff=yoy-xox;
             if(diff%2==0){
                cnt+=diff/2;
             }else{
                cnt+=diff/2;
                cnt++;
             }
         }
         else
         {
             
            //  xox *=2;
            xox = xox+xox;
             cnt++;
             int diff=yoy-xox;
             if(diff%2==0){
                cnt+=diff/2;
             }else{
                cnt+=diff/2;
                cnt++;
             }
         }
	    cout<<count<<endl;