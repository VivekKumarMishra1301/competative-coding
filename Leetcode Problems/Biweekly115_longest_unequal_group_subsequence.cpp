class Solution {
public:
    int hm(string st1,string st2){
        if(st1.size()==st2.size()&&st1.size()==1&&st1!=st2){
            return 1;
        }
        if(st1.size()!=st2.size()){
            return 15;
        }
        int dist=0;
        for(int i=0;i<st1.size();i++){
            if(st1[i]!=st2[i]){
                dist++;
            }
        }
        return dist;
//         map<char,int>mp1;
//         map<char,int>mp2;
//         for(auto i:st1){
//             mp1[i]++;
//         }
//         for(auto i:st2){
//             mp2[i]++;
//         }
//         int dist=0;
//         for(auto i:mp1){
//             if(mp2.find(i.first)==mp2.end()){
//                 dist++;
//             }
//         }
        
//         for(auto i:mp2){
//             if(mp1.find(i.first)==mp1.end()){
//                 dist++;
//             }
//         }
//         cout<<dist<<" ";
//         return dist;
        
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string>hold;
    //     for(int j=0;j<words.size();j++){
    //     vector<int>temp;
    //         vector<string>hold1;
    //     for(int i=j;i<words.size();i++){
    //         if(temp.size()==0){
    //             temp.push_back(groups[i]);
    //             hold1.push_back(words[i]);
    //         }else if(groups[i]!=temp[temp.size()-1]&&hold1[hold1.size()-1].size()==words[i].size()&&hm(hold1[hold1.size()-1],words[i])==1){
    //             temp.push_back(groups[i]);
    //             hold1.push_back(words[i]);
    //         }
    //     }
    //      if(hold1.size()>=hold.size()){
    //          hold=hold1;
    //      }   
    // }
        map<string,vector<int>>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]].push_back(i);
            for(int j=i-1;j>=0;j--){
                if(groups[i]!=groups[j]&&words[i].size()==words[j].size()&&hm(words[i],words[j])==1){
                    if(1+mp[words[j]].size()>mp[words[i]].size()){
                        vector<int>m=mp[words[j]];
                        m.push_back(i);
                        mp[words[i]]=m;
                    }
                }
            }
        }
        int sz=0;
        string ans;
        for(auto i:mp){
            if(i.second.size()>=sz){
                sz=i.second.size();
                ans=i.first;
            }
        }
        for(int i=0;i<words.size();i++){
            cout<<mp[words[i]].size()<<" ";
        }
        cout<<endl;
        vector<int>k=mp[ans];
        // reverse(k.begin(),k.end());
        for(int i=0;i<k.size();i++){
            hold.push_back(words[k[i]]);
        }
        
        return hold;
    }
};