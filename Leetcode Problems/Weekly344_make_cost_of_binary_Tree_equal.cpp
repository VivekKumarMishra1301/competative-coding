class Solution
{
public:
    int traverse(int ind, int n, vector<int> &cost, int &cnt)
    {
        if (ind > n)
        {

            // hold.push_back(sum);

            return 0;
        }

        // sum+=(long)cost[ind-1];

        int l = traverse(2 * ind, n, cost, cnt);

        // if(2*ind+1<=n)
        int r = traverse(2 * ind + 1, n, cost, cnt);
        int diff = abs(l - r);
        cnt += diff;
        return cost[ind - 1] + max(l, r);
    }

    int minIncrements(int n, vector<int> &cost)
    {
        vector<int> hold;
        int cnt = 0;
        int get = traverse(1, n, cost, cnt);
        // int maxi=*max_element(hold.begin(),hold.end());
        // for(auto i:hold){
        //     cout<<i<<" ";
        //  cnt+=abs(i-maxi);
        // }
        return cnt;
    }
};