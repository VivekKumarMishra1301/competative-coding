class Solution {
public:
    string makeGood(string s) {
        if (s.size() == 1 || s.size() == 0) {
            return s;
        }
        stack<char>hold;
        for (int i = 0;i < s.size() - 1;i++) {
            if (s[i] == (s[i + 1] + 32) || (s[i] + 32) == (s[i + 1])) {
                // hold.push(s[i]);
                //  hold.push(s[i]);
                return makeGood(s.substr(0, i) + s.substr(i + 2));
            }


        }
        return s;

    }
};