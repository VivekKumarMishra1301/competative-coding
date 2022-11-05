class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>hold;
        for (int i = 0;i < prices.size();i++) {
            bool check = false;
            for (int j = i + 1;j < prices.size();j++) {
                if (prices[j] <= prices[i]) {
                    hold.push_back(prices[i] - prices[j]);
                    check = true;
                    break;
                }
            }
            if (check == false) {
                hold.push_back(prices[i]);
            }
        }
        return hold;
    }
};


//another approach for the same problem using the stack 
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        //its next smaller element to the right
        stack<int> s;
        for (int i = prices.size() - 1;i >= 0;i--)
        {
            while (!s.empty() && s.top() > prices[i])
                s.pop();
            int x = prices[i];
            if (!s.empty()) prices[i] -= s.top();
            s.push(x);
        }
        return prices;
    }
};