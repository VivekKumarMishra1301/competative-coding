class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string>hold;
        vector<int>temp;
        for(int i=0;i<words.size();i++){
            if(temp.size()==0){
                temp.push_back(groups[i]);
                hold.push_back(words[i]);
            }else if(groups[i]!=temp[temp.size()-1]){
                temp.push_back(groups[i]);
                hold.push_back(words[i]);
            }
        }
        return hold;
    }
};