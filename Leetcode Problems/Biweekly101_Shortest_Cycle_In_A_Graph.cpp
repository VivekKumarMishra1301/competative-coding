class Solution
{
public:
    //     int mini=INT_MAX;
    //     map<int,vector<int>>adj;
    //     void dfs(int ind,int parent,vector<bool>&visited,int noc,vector<int>&dist){
    //         dist[ind]=noc;
    //         if(visited[ind]){
    //             if(ind!=parent){
    //         cout<<noc<<" "<<ind<<endl;
    //                 mini=min(mini,abs(dist[ind]+1));
    //             }
    //             return;
    //         }
    //         visited[ind]=true;
    //         for(auto i:adj[ind]){
    //             if(i!=parent)
    //             dfs(i,ind,visited,noc+1,dist);
    //         }
    //     }

    //     int findShortestCycle(int n, vector<vector<int>>& edges) {
    //         for(int i=0;i<edges.size();i++){
    //             adj[edges[i][0]].push_back(edges[i][1]);
    //             adj[edges[i][1]].push_back(edges[i][0]);
    //         }
    //         vector<bool>visited(n,false);
    //         vector<int>dist(n,INT_MAX);
    //         for(int i=0;i<n;i++){
    //             if(!visited[i]){
    //                 cout<<"st"<<endl;
    //                 dfs(i,-1,visited,0,dist);
    //             }
    //         }
    //         if(mini==INT_MAX){
    //             return -1;
    //         }
    //         return mini;

    //     }
    int ans = INT_MAX;

    void dfs(int node, int par, vector<int> adj[], vector<int> &val, int d)
    {
        val[node] = d;
        for (auto it : adj[node])
        {
            if (val[it] == 0)
            {
                dfs(it, node, adj, val, d + 1);
            }
            else if (it != par)
            {
                ans = min(ans, abs(d - val[it]) + 1);
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> val(n, 0);
        for (int i = 0; i < n; i++)
        {
            dfs(i, -1, adj, val, 1);
            fill(val.begin(), val.end(), 0);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};