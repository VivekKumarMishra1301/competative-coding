class Solution {
public:
    bool isValid(string s) {
        stack<char>hold;
        for (int i = 0;i < s.size();i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                hold.push(s[i]);
            }
            else if (s[i] == ')') {
                if (hold.empty()) {
                    return false;
                }
                if (hold.top() == '(') {
                    hold.pop();
                }
                else {
                    return false;
                }
            }
            else if (s[i] == '}') {
                if (hold.empty()) {
                    return false;
                }
                if (hold.top() == '{') {
                    hold.pop();
                }
                else {
                    return false;
                }
            }
            else if (s[i] == ']') {
                if (hold.empty()) {
                    return false;
                }
                if (hold.top() == '[') {
                    hold.pop();
                }
                else {
                    return false;
                }
            }
        }

        if (hold.empty()) {
            return true;
        }
        return false;

    }
};