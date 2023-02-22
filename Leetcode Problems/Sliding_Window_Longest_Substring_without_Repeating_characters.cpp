class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //       vector<int>hold;
        //         int max=1;
        //         int arr[256];
        //         unordered_map<char,int>meraMap;
        //         for(int i=0;i<s.size();i++){
        //             if(arr[s[i]]!=0){

        //                 arr[s[i]]=0;
        //                 hold.push_back(max);
        //                 max=1;

        //                 continue;

        //             }
        //             arr[s[i]]++;
        //             max++;
        //         }
        //         sort(hold.begin(),hold.end());
        //         return hold[hold.size()-1];
        if (s.size() == 0)
        {
            return 0;
        }

        unordered_map<char, int> meraMap;
        int st = 0;
        int en = 0;
        int size = 1;
        while (en < s.size())
        {
            if (meraMap.find(s[en]) == meraMap.end())
            {
                meraMap[s[en]]++;
                // en++;
            }
            else
            {
                while (st < en && meraMap.find(s[en]) != meraMap.end())
                {
                    meraMap.erase(s[st]);
                    st++;
                }
                meraMap[s[en]]++;
                // en++;
            }

            size = max(en - st + 1, size);
            cout << en << "," << st << ":" << size << " ";
            en++;
        }
        return size;
    }
};