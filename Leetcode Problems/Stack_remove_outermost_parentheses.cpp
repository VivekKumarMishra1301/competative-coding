class Solution {
public:
    string removeOuterParentheses(string s) {
        if(s.size()==0){
            return "";
        }
        stack<char>hold;
        string res="";
        for(int i=0;i<s.size();i++){
            if(hold.size()!=0&&s[i]=='('){
                res=res+s[i];
                
            }
            if(s[i]=='('){
                hold.push(s[i]);
                continue;
            }
            char top=')';
            if(s[i]==')'){
                hold.pop();
                if(hold.size()!=0){
                    res=res+s[i];
                }
            }
            
        }
        return res;
    }
};