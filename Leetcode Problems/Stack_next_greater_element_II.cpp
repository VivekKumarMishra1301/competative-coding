class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> hold;
        int n = nums.size();
        stack<int> st;
        for (int i = 2 * n; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }
            if (i < n)
            {
                if (!st.empty())
                {
                    hold.push_back(st.top());
                    // st.push(nums[i]);
                }
                else
                {
                    hold.push_back(-1);
                }
            }
            st.push(nums[i % n]);
        }
        reverse(hold.begin(), hold.end());
        return hold;
    }
};