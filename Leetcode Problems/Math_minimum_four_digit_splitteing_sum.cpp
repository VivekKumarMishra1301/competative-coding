class Solution {
public:
    int minimumSum(int num) {

        vector<int>hold;
        while (num > 0) {
            hold.push_back(num % 10);
            num = num / 10;
        }
        sort(hold.begin(), hold.end());
        int num1 = hold[0] * 10 + hold[2];
        int num2 = hold[1] * 10 + hold[3];
        return num1 + num2;

    }
};