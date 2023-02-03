class Solution
{
public:
    string convert(string s, int numRows)
    {
        // cout<<s.size()<<endl;
        unordered_map<int, vector<int>> meraMap;
        if (numRows == 1)
        {
            return s;
        }
        vector<vector<int>> hold(numRows, vector<int>(1000, -1));

        int st = 0;
        // int r=0;
        // int c=0;

        while (st < s.size())
        {
            while (r < numRows && st < s.size())
            {
                // cout<<r<<c<<":";
                // cout<<st<<" ";
                meraMap[r++].push_back(st++);
                // hold[r++][c]=st++;
            }

            r--;
            r--;

            while (r >= 0 && st < s.size())
            {
                // cout<<r<<c<<":";
                // cout<<st<<" ";
                meraMap[r--].push_back(st++);
                // hold[r--][++c]=st++;
            }
            r = 1;
        }

        string ans = "";
        // return ans;

        //         int count=0;
        //         cout<<endl;
        //         for(int i=0;i<numRows;i++){
        //             for(int j=0;j<=c;j++){
        //                 if(hold[i][j]!=-1){

        //                 ans+=s[hold[i][j]];
        //                 count++;
        //                 }
        //                 if(count==s.size()){
        //                     break;
        //                 }
        //                 cout<<hold[i][j]<<" ";
        //             }
        //             cout<<endl;
        //         }
        for (int i = 0; i < numRows; i++)
        {
            vector<int> vect = meraMap[i];
            for (int j = 0; j < vect.size(); j++)
            {
                ans += s[vect[j]];
            }
        }

        return ans;
    }
};