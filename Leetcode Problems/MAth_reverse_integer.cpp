class Solution {
public:
    int reverse(int x) {
        long int num = x;
        long int rev = 0;
        if (x >= 0) {

            while (num > 0) {
                rev = rev * 10 + num % 10;
                num = num / 10;
            }

        }
        else {

            while (num < 0) {
                rev = rev * 10 + num % 10;
                num = num / 10;
            }

        }
        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }
        return rev;
    }
};