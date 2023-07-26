class Solution
{
public:
    double distCal(vector<int> &dist, int sp)
    {
        double t = 0;
        for (int i = 0; i < dist.size(); i++)
        {
            double t1 = dist[i] / (double)sp;
            if (i != dist.size() - 1)
            {
                t += t1;
                t = ceil(t);
            }
            else
            {
                t += t1;
            }
            // cout<<t1<<" "<<t<<endl;
        }
        // cout<<"After function"<<endl;
        return t;
    }

    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int n = dist.size();
        if (hour < n - 1)
        {
            return -1;
        }
        int maxi = 100000001;
        int mini = 1;
        // for(int i=0;i<dist.size();i++){
        //     if(dist[i]>maxi){
        //         maxi=dist[i];
        //     }
        //     if(dist[i]<mini){
        //         mini=dist[i];
        //     }
        // }
        int ans = INT_MAX;
        while (mini <= maxi)
        {
            int mid = (mini + maxi) / 2;
            double tt = distCal(dist, mid);
            // cout<<mid<<" "<<tt<<" ";
            if (tt <= hour)
            {
                ans = min(maxi, mid);
                maxi = mid - 1;
            }
            else
            {
                mini = mid + 1;
            }

            cout << endl;
        }
        // cout<<"line changed"<<endl;
        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};