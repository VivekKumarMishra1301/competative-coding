class Solution {
public:
    
    bool dfs(int ind,map<int,vector<int>>&mp,vector<bool>&visited){
        if(visited[ind]){
            return false;
        }
        
        bool ans=true;
        visited[ind]=true;
        for(auto i:mp[ind]){
            ans=ans&&dfs(i,mp,visited);
        }
        cout<<ind<<":"<<ans<<endl;
        return ans;
    }
    
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        map<int,vector<int>>mp;
       vector<bool>visited(n,false);
        vector<bool>chld(n,false);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                
            mp[i].push_back(leftChild[i]);
                chld[leftChild[i]]=true;
            }
            if(rightChild[i]!=-1){
                
            mp[i].push_back(rightChild[i]);
            chld[rightChild[i]]=true;
            }
            // if(leftChild[i]==-1&&rightChild[i]==-1){
            //     visited[i]=true;
            // }
            // chld[]
        }
        
        // visited[0]=true;
        
        int cnt=0;
        int rt=0;
        for(int i=0;i<n;i++){
            if(!chld[i]){
                rt=i;
                cnt++;
            }
            if(cnt>1){
                return false;
            }
        }
        
        
        bool hold=dfs(rt,mp,visited);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return hold;
        
        
        
    }
};
