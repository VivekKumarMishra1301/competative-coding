class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>hold;
        stack<int>arr;
        int i = 1;
        int ind = 0;
        while (ind < target.size()) {
            arr.push(i++);
            hold.push_back("Push");
            if (arr.top() == target[ind]) {
                ind++;
            }
            else {
                arr.pop();
                hold.push_back("Pop");
            }
        }
        return hold;
    }
};