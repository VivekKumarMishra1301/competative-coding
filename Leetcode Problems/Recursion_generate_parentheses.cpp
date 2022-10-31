class Solution {
public:
    void valid(int op, int cl, string res, vector<string>& hold) {
        if (op == 0 && cl == 0) {
            hold.push_back(res);
            return;
        }
        if (op != 0) {
            valid(op - 1, cl, res + "(", hold);
        }
        if (cl > op) {
            valid(op, cl - 1, res + ")", hold);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>hold;
        string res = "";
        valid(n, n, res, hold);
        return hold;
    }
};