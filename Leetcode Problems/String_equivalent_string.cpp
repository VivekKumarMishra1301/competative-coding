class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
     string str="";
        string st2="";
        for(int i=0;i<word1.size();i++){
            str+=word1[i];
        }
        
        
        for(int i=0;i<word2.size();i++){
            st2+=word2[i];
        }
        return str==st2;
    }
};