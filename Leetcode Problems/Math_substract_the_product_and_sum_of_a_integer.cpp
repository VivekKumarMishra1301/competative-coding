class Solution {
public:
    int subtractProductAndSum(int n) {
        int x = n;
        int mul = 1;
        int sum = 0;
        while (x > 0) {
            mul = mul * (x % 10);
            sum = sum + x % 10;
            x = x / 10;
        }
        return mul - sum;
    }
};