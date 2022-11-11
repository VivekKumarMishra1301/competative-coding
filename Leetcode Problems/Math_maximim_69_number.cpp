class Solution {
public:
    int maximum69Number(int num) {
        string a = to_string(num);
        string b = a;
        stack<int>hold;
        for (int i = 0;i < a.size();i++) {
            if (a[i] == '6') {
                b[i] = '9';
                hold.push(stoi(b));
                b = a;
            }
        }
        if (hold.empty()) {
            return num;
        }
        int max = hold.top();
        while (!hold.empty()) {
            if (hold.top() > max) {
                max = hold.top();
            }
            hold.pop();
        }
        return max;
    }
};s