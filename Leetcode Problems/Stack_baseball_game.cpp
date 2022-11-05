class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int>hold;
        for (int i = 0;i < operations.size();i++) {
            if (operations[i] == "+") {
                int i = 0;
                int sum = 0;
                stack<int>gain;
                while (!hold.empty() && i < 2) {
                    sum = sum + hold.top();
                    gain.push(hold.top());
                    hold.pop();
                    i++;
                }
                while (!gain.empty()) {
                    hold.push(gain.top());
                    gain.pop();
                }
                hold.push(sum);
            }
            else if (operations[i] == "D") {
                hold.push(hold.top() * 2);
            }
            else if (operations[i] == "C") {
                hold.pop();
            }
            else {
                hold.push(stoi(operations[i]));
            }
        }

        int totsum = 0;
        while (!hold.empty()) {
            totsum = totsum + hold.top();
            hold.pop();
        }
        return totsum;
    }
};