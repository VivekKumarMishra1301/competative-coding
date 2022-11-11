class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>hold;
        for (int i = 0;i < bank.size();i++) {
            int count = 0;
            for (int j = 0;j < bank[i].size();j++) {
                if (bank[i][j] == '1') {
                    count++;
                }
            }
            hold.push_back(count);
        }
        int sum = 0;
        for (int i = 0;i < hold.size() - 1;i++) {
            for (int j = i + 1;j < hold.size();j++) {
                if (hold[j] != 0) {

                    sum = sum + hold[i] * hold[j];
                    break;
                }
            }
        }
        return sum;
    }
};