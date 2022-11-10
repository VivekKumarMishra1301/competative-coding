class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>hold;
        while (n--) {
            hold.push_back(start);
            start = start + 2;
        }
        int xorop = hold[0];
        for (int i = 1;i < hold.size();i++) {
            xorop = xorop ^ hold[i];
        }
        return xorop;

    }
};