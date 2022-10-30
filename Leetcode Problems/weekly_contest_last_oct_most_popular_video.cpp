class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<int>hold;
        vector<vector<string>>result;
        for (int i = 0;i < creators.size();i++) {
            string a = creators[i];
            string b = ids[i];
            int maxview = views[i];
            int totalviews = views[i];
            for (int j = i + 1;j < creators.size();j++) {
                if (creators[j] == a && creators[j] != "") {
                    creators[j] = "";

                    totalviews += views[j];
                    if (views[j] > maxview) {
                        b = ids[j];
                        maxview = views[j];
                    }
                }
            }
            vector<string>res;
            res.push_back(a);
            res.push_back(b);
            result.push_back(res);
            hold.push_back(totalviews);
        }
        vector<int>maxind;
        int max = hold[0];
        for (int i = 0;i < hold.size();i++) {
            if (hold[i] > max) {
                max = hold[i];
            }
        }
        for (int i = 0;i < hold.size();i++) {
            if (hold[i] == max) {
                maxind.push_back(i);
            }
        }
        vector<vector<string>>ans;
        for (int i = 0;i < maxind.size();i++) {
            ans.push_back(result[maxind[i]]);
        }
        return ans;
    }
};