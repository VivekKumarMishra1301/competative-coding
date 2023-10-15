class Solution {
public:
    string lexico(string st1,string st2){
        string ns="";
        bool flag=true;
        for(int i=0;i<st1.size();i++){
            if(st1[i]=='0'&&flag){
                continue;
            }else{
                flag=false;
            }
            ns+=st1[i];
        }
        st1=ns;
        ns="";
         for(int i=0;i<st2.size();i++){
            if(st2[i]=='0'&&flag){
                continue;
            }else{
                flag=false;
            }
            ns+=st2[i];
        }
        st2=ns;
        
        int nu=st1.size();
        if(st1.size()>st2.size()){
            return st2;
        }
        if(st1.size()<st2.size()||st1==st2){
            return st1;
        }
        
        for(int i=0;i<st1.size();i++){
            if(st1[i]==st2[i]){
                continue;
            }else if(st1[i]=='0'){
                return st1;
            }else if(st2[i]=='0'){
                return st2;
            }
        }
        return st1;
        
        
    }
    string shortestBeautifulSubstring(string s, int k) {
        string hold="";
        for(int i=0;i<s.size();i++){
            int cnt=0;
            int j=i;
            string ns="";
            // ns+=s[i];
            while(j<s.size()){
                ns+=s[j];
                if(s[j]=='1'){
                    cnt++;
                }
                if(cnt==k){
                    if(hold.size()==0){
                        hold=ns;
                        break;
                    }
                    hold=lexico(ns,hold);
                    break;
                }
                j++;
            }
            
        }
        // string ns="";
        // bool flag=true;
        // for(int i=0;i<hold.size();i++){
        //     if(hold[i]=='0'&&flag){
        //         continue;
        //     }else{
        //         flag=false;
        //     }
        //     ns+=hold[i];
        // }
        return hold;
    }
};