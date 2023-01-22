class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        vector<int> hold;
        vector<vector<int>> temp;
        unordered_map<int, int> meraMap;
        for (int i = 0; i < score.size(); i++)
        {
            meraMap[score[i][k]] = i;
        }
        for (auto i : meraMap)
        {
            cout << i.first << ":" << i.second << " ";
        }
        for (int i = 0; i < score.size(); i++)
        {
            hold.push_back(score[i][k]);
        }
        sort(hold.begin(), hold.end(), greater<int>());

        for (int i = 0; i < hold.size(); i++)
        {
            auto itr = meraMap.find(hold[i]);
            int ind = itr->second;
            temp.push_back(score[ind]);
        }

        //   for(int i=0;i<score.size();i++){
        //     score[i][k]=hold[i];
        // }

        return temp;
    }
};