class Solution {
public:
    int minOperations(vector<string>& logs) {
        if (logs.size() == 0) {
            return 0;
        }
        stack<string>hold;
        for (int i = 0;i < logs.size();i++) {
            if (logs[i] == "../") {
                if (!hold.empty()) {
                    hold.pop();
                }
            }
            else if (logs[i] == "./") {
                continue;
            }
            else {
                hold.push(logs[i]);
            }
        }

        int count = 0;
        while (!hold.empty()) {
            count++;
            hold.pop();
        }
        return count;
    }
};