class Solution {
public:
    string addBinary(string a, string b) {
        string hold="";
        int carry=0;
        int e1=a.size()-1;
        int e2=b.size()-1;
        while(e1>=0&&e2>=0){
            int one=0;
            int zero=0;
            if(a[e1]=='0'){
                zero++;
            }else if(a[e1]=='1'){
                one++;
            }
            
            if(b[e2]=='1'){
                one++;
            }else if(b[e2]=='0'){
                zero++;
            }
            
            if((one+carry)==1){
                carry=0;
                hold='1'+hold;
            
            }else if((one+carry)==0){
                hold='0'+hold;
                carry=0;
            }else if((one+carry)%2==0){
                hold='0'+hold;
                carry=1;}
        else{
                hold='1'+hold;
                carry=1;
            }
            e1--;
            e2--;
        }
        
        while(e1>=0){
            int one=0;
            int zero=0;
            if(a[e1]=='0'){
                zero++;
            }else if(a[e1]=='1'){
                one++;
            }
            if((one+carry)==1){
                carry=0;
                hold='1'+hold;
            }else if((one+carry)==0){
                hold='0'+hold;
                carry=0;
            }else if((one+carry)%2==0){
                hold='0'+hold;
                carry=1;
            }else{
                hold='1'+hold;
                carry=1;
            }
            e1--;
        }
         while(e2>=0){
             int one=0;
             int zero=0;
            if(b[e2]=='0'){
                zero++;
            }else if(b[e2]=='1'){
                one++;
            }
            if((one+carry)==1){
                carry=0;
                hold='1'+hold;
            }else if((one+carry)==0){
                hold='0'+hold;
                carry=0;
            }else if((one+carry)%2==0){
                hold='0'+hold;
                carry=1;
            }else{
                hold='1'+hold;
                carry=1;
            }
            e2--;
        }
        if(carry==1){
            hold='1'+hold;
        }
        return hold;
    }
};