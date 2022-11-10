class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        int x = num;
        while (x > 0) {
            if (x % 2 == 0) {
                x = x / 2;
                count++;
            }
            else {
                x = x - 1;
                count++;
            }
        }
        return count;
    }
};