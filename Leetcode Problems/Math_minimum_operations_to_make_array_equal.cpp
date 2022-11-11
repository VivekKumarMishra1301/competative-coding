class Solution {
public:
    int minOperations(int n) {
        int last = 2 * (n - 1) + 1;
        int mid = (last + 1) / 2;
        int count = 0;
        for (int i = 0;i < n / 2;i++) {
            int val = (2 * i) + 1;
            int diff = abs(mid - val);
            count = count + diff;
        }
        return count;
    }
};