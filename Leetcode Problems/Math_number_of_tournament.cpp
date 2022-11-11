class Solution {
public:
    int numberOfMatches(int n) {
        if (n == 1) {
            return 0;
        }
        int a = n / 2;
        int b = n - a;
        return a + numberOfMatches(b);

    }
};