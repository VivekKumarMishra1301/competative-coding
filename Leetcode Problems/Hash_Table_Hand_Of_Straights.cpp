class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        //         if(hand.size()%groupSize!=0){
        //             return false;
        //         }
        //         sort(hand.begin(),hand.end());
        //         unordered_map<int,int>meraMap;
        //         for(auto i:hand){
        //             meraMap[i]++;
        //         }
        //         vector<int>hold;
        //         hold.push_back(hand[0]);
        //         cout<<hold[0]<<":"<<meraMap[hold[0]]<<" ";
        //         for(int i=1;i<hand.size();i++){
        //             if(hand[i]!=hand[i-1]){
        //                 hold.push_back(hand[i]);
        //                 cout<<hold[hold.size()-1]<<":"<<meraMap[hold[hold.size()-1]]<<" ";
        //             }
        //         }

        //         int cnt=meraMap[hold[0]];
        //         if(meraMap.size()%groupSize!=0){
        //             return false;
        //         }
        //         for(int i=1;i<hold.size();i++){
        //             if(hold[i]!=hold[i-1]+1){
        //                 if(cnt%groupSize!=0){
        //                     return false;
        //                 }
        //                 cnt=meraMap[hold[i]];

        //             }else{
        //                 cnt+=meraMap[hold[i]];
        //                 if(meraMap[hold[i]]<meraMap[hold[i-1]]&&cnt%groupSize!=0){
        //                     return false;
        //                 }
        //             }
        //         }
        //         if(cnt%groupSize!=0){
        //             return false;
        //         }
        //         return true;
        map<int, int> meraMap;
        for (int i = 0; i < hand.size(); i++)
        {
            meraMap[hand[i]]++;
        }

        for (auto x = meraMap.begin(); x != meraMap.end();)
        {
            if (meraMap[x->first] > 0)
            {
                for (int i = 0; i < groupSize; i++)
                {
                    if (meraMap[x->first + i] > 0)
                    {
                        meraMap[x->first + i]--;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                x++;
            }
        }
        return true;
    }
};




 