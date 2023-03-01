class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> hold;

        // for(int i=0;i<pattern.size();i++){
        //     meraMap[pattern[i]].push_back(i);
        // }
        for (int i = 0; i < words.size(); i++)
        {
            map<char, vector<int>> meraMap;
            map<char, vector<int>> mp;
            bool flag = true;
            for (int j = 0; j < words[i].size(); j++)
            {
                meraMap[pattern[j]].push_back(j);
                mp[words[i][j]].push_back(j);
                if (meraMap[pattern[j]] != mp[words[i][j]])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                hold.push_back(words[i]);
            }
        }
        //         vector<int>pfreq;
        //         // pfreq.push_back(1);
        //         int cnt=1;
        //         map<char,int>m;
        //         m[pattern[0]]++;
        //         for(int i=1;i<pattern.size();i++){
        //             m[pattern[i]]++;
        //             if(pattern[i]!=pattern[i-1]){
        //                 pfreq.push_back(cnt);
        //                 cnt=1;
        //             }else{
        //                 cnt++;
        //             }
        //         }
        //         pfreq.push_back(cnt);

        //         // for(auto i:pattern){
        //         //     pfreq[i-'a']++;
        //         // }
        //         // vector<int>red;
        //         // for(int i=0;i<26;i++){
        //         //     if(pfreq[i]!=0){
        //         //         red.push_back(pfreq[i]);
        //         //         cout<<pfreq[i]<<" ";
        //         //     }
        //         // }
        //         //     cout<<endl;

        //         for(int i=0;i<words.size();i++){
        //             vector<int>freq;
        //             map<char,int>q;
        //             // for(auto j:words[i]){
        //             //     freq[j-'a']++;
        //             // }
        //             // vector<int>newred;
        //             // for(int l=0;l<26;l++){
        //             //     if(freq[l]!=0){
        //             //         newred.push_back(freq[l]);
        //             //         if(words[i]=="mee")
        //             //             cout<<freq[l]<<" ";
        //             //     }
        //             // }

        //             int cn=1;
        //             q[words[i][0]]++;
        //             for(int j=1;j<words[i].size();j++){
        //                 q[words[i][j]]++;
        //                 if(words[i][j]!=words[i][j-1]){
        //                     freq.push_back(cn);
        //                     cn=1;
        //                 }else{
        //                     cn++;
        //                 }
        //             }
        //             freq.push_back(cn);
        //             if(freq==pfreq&&m.size()==q.size()){
        //                 hold.push_back(words[i]);
        //             }
        //         }
        return hold;
    }
};