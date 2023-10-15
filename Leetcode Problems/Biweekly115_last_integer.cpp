class Solution {
public:
    bool isDigit(string str){
        for(auto i:str){
            if(!isdigit(i)){
                return false;
            }
        }
        return true;
    }
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int>hold;
        vector<int>curr;
        int i=0;
        while(i<words.size()){
            while(i<words.size()&&isDigit(words[i])){
                curr.push_back(stoi(words[i]));
                i++;
            }
            int cnt=0;
            while(i<words.size()&&(!isDigit(words[i]))){
                cnt++;
                i++;
            }
            vector<int>n=curr;
            // reverse(n.begin(),n.end());
            int m=n.size()-1;
            while(cnt){
                if(m>=0){
                    hold.push_back(n[m]);
                }else{
                    hold.push_back(-1);
                }
                cnt--;
                m--;
            }
            
        }
        return hold;
    }
};