class Solution {
public:
    string oddString(vector<string>& words) {
        vector<vector<int>>hold;
        int size = 0;
        for (int i = 0;i < words.size();i++) {
            string word = words[i];

            vector<int>wait(word.size() - 1);
            for (int i = 1;i < word.size();i++) {
                int a = word[i - 1] - 97;
                int b = word[i] - 97;
                wait[i - 1] = b - a;
            }
            hold.push_back(wait);

        }
        vector<int>p1;
        for (int i = 0;i < hold.size();i++) {
            bool check = true;
            p1 = hold[i];
            for (int j = 0;j < hold.size();j++) {
                if (p1 == hold[j] && i != j) {
                    check = false;
                }
            }
            if (check) {
                return words[i];
            }
        }

        return words[0];
    }
};