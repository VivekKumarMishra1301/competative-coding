class Solution {
public:
    int maxDepth(string s) {
        if (s.size() == 0) {
            return 0;
        }
        stack<char>st;
        int depth = 0;
        for (int i = 0;i < s.size();i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                if (st.size() > depth) {
                    depth = st.size();
                }
            }
            else
                if (s[i] == ')')
                    st.pop();
        }


        return depth;
    }
};