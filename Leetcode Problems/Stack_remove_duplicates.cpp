class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> hold;
        for (int i = 0; i < s.size(); i++)
        {
            if (hold.empty())
            {
                hold.push(s[i]);
            }
            else if (s[i] == hold.top())
            {
                hold.pop();
            }
            else
            {
                hold.push(s[i]);
            }
        }

        string res = "";
        while (!hold.empty())
        {
            res = hold.top() + res;
            hold.pop();
        }

        //         for(int i=0;i<s.size();i++){
        //             // if(i!=s.size()-1){

        //             if(s[i]==s[i+1]){
        //                 i++;
        //             }else{
        //                 hold.push(s[i]);
        //             }
        //          // }else{
        //          //        hold.push(s[i]);
        //          //    }
        // }
        //         string res="";
        //         while(!hold.empty()){
        //             char top=hold.top();
        //             hold.pop();
        //             if(!hold.empty()){

        //             if(top!=hold.top()){
        //                 res=top+res;
        //             }else{
        //                 hold.pop();
        //             }
        //             }else{
        //                 res=top+res;
        //             }
        //         }

        return res;
    }
};