class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int>hold;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i = 0;
        int carry = 0;
        while (i < num1.size() && i < num2.size()) {
            int a = num1[i] - '0';
            int b = num2[i] - '0';
            int res = a + b + carry;
            hold.push_back(res % 10);
            if (res > 9) {
                carry = 1;
            }
            else {
                carry = 0;
            }
            i++;
        }

        while (i < num1.size()) {
            int a = num1[i] - '0';
            int res = a + carry;
            hold.push_back(res % 10);
            if (res > 9) {
                carry = 1;
            }
            else {
                carry = 0;
            }
            i++;
        }
        while (i < num2.size()) {
            int a = num2[i] - '0';
            int res = a + carry;
            hold.push_back(res % 10);
            if (res > 9) {
                carry = 1;
            }
            else {
                carry = 0;
            }
            i++;
        }
        if (carry == 1) {
            hold.push_back(carry);
        }
        reverse(hold.begin(), hold.end());
        string res = "";
        for (int j = 0;j < hold.size();j++) {
            res.push_back('0' + hold[j]);
        }
        return res;
    }
};