class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        vector<int>hold(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1;i >= 0;i--) {
            int carry = 0;
            for (int j = num2.size() - 1;j >= 0;j--) {
                int res = (num1[i] - '0') * (num2[j] - '0');

                hold[i + j + 1] = hold[i + j + 1] + res + carry;
                int fres = hold[i + j + 1];
                hold[i + j + 1] = fres % 10;
                if (fres > 9) {
                    carry = fres / 10;

                }
                else {
                    carry = 0;
                }
                if (j == 0 && carry != 0) {
                    hold[i + j] = carry;
                }
            }
        }
        string res = "";
        int k = 0;
        while (hold[k] == 0) {
            k++;
        }
        for (int i = k;i < hold.size();i++) {
            res.push_back('0' + hold[i]);
        }
        return res;
    }
};