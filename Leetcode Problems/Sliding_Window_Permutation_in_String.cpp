class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        //         unordered_map<char,int>skamap;
        //         unordered_map<char,int>tkamap;
        //         for(auto i:s1){
        //             skamap[i]++;
        //         }

        //          for(auto i:s2){
        //             tkamap[i]++;
        //         }

        //          for(auto i:s1){
        //             if(skamap[i]>tkamap[i]){
        //                 return false;
        //             }
        //         }
        //         return true;

        vector<int> smap(26, 0);
        vector<int> tmap(26, 0);
        int len1 = s1.size();
        int len2 = s2.size();
        if (len2 < len1)
        {
            return false;
        }

        int l = 0;
        int r = 0;
        while (r < len1)
        {
            smap[s1[r] - 'a'] += 1;
            tmap[s2[r] - 'a'] += 1;
            r++;
        }

        r--;
        while (r < len2)
        {
            if (smap == tmap)
            {
                return true;
            }
            r++;
            if (r != len2)
            {
                tmap[s2[r] - 'a'] += 1;
            }
            tmap[s2[l] - 'a'] -= 1;
            l++;
        }

        return false;
    }
};