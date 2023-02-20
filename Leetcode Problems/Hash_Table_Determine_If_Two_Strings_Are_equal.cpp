class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
        {
            return false;
        }
        unordered_map<char, int> meraMap;
        for (auto i : word1)
        {
            meraMap[i]++;
        }
        unordered_map<char, int> teraMap;
        for (auto i : word2)
        {
            if (meraMap.count(i) == 0)
            {
                return false;
            }
            teraMap[i]++;
        }

        for (auto i : word1)
        {
            if (teraMap.count(i) == 0)
            {
                return false;
            }
        }
        vector<int> f1;
        vector<int> f2;
        for (auto i : meraMap)
        {
            f1.push_back(i.second);
        }
        for (auto i : teraMap)
        {
            f2.push_back(i.second);
        }

        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        if (f1 == f2)
        {
            return true;
        }
        return false;

        //         int ava=0;
        //         int unm=0;
        //         for( auto i:teraMap){
        //             if(meraMap.count(i.first)!=0){

        //                 if(i.second>=meraMap[i.first]){
        //                     ava=ava+(i.second-meraMap[i.first]);
        //                     meraMap[i.first]=0;
        //                 }else{
        //                     unm=unm+(meraMap[i.first]-i.second);
        //                     meraMap[i.first]=0;
        //                 }
        //             }else{
        //                 return false;
        //                 // unm+=i.second;
        //             }
        //         }
        //         for(auto i:meraMap){
        //             if(teraMap.count(i.first)==0){
        //                 return false;
        //             }
        //             unm+=i.second;
        //         }
        //             if(ava==unm&&ava!=1){
        //                 return true;
        //             }
        //         return false;
    }
};