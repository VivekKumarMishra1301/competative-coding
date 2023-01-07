class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        int ind = -1;
        vector<int> hold;
        int fuel = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            hold.push_back(gas[i] - cost[i]);
            fuel += hold[i];
            cout << hold[i] << " ";
        }
        if (fuel < 0)
        {
            return -1;
        }
        int sum = 0;
        ind = 0;
        for (int i = 0; i < hold.size(); i++)
        {
            if (sum < 0)
            {
                sum = hold[i];
                ind = i;
                continue;
            }
            sum += hold[i];
        }

        return ind;

        //         int n=gas.size();
        //         // int
        //         for(int i=0;i<n;i++){
        //             int fuel=gas[i];
        //             if(gas[i]<cost[i]){
        //                 continue;
        //             }else{
        //                 int k=(i+1)%n;
        //                 fuel=fuel-cost[i];
        //                 bool flag=true;
        //                 while(k!=i){
        //                     if(fuel<=0){
        //                         flag=false;
        //                         break;
        //                     }
        //                     fuel+=gas[k]-cost[k];
        //                        k=(k+1)%n;

        //                 }
        //                 if(flag&&fuel>=0){
        //                     return i;
        //                 }
        //             }

        //         }
        //         return -1;
    }
};