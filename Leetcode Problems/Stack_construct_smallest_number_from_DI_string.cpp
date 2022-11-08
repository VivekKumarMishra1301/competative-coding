class Solution {
public:
    string smallestNumber(string pattern) {
        string output = "";
        stack<int>hold;
        for (int i = 0;i <= pattern.length();i++) {
            hold.push(i + 1);
            if (i == pattern.length() || pattern[i] == 'I') {
                while (!hold.empty()) {
                    output += to_string(hold.top());
                    hold.pop();
                }
            }
        }
        return output;
    }
};