class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>hold;
        stack<int>index;
        for (int i = nums1.size() - 1;i >= 0;i--) {
            for (int j = 0;j < nums2.size();j++) {
                if (nums1[i] == nums2[j]) {
                    index.push(j);
                    break;
                }
            }
        }

        for (int i = 0;i < nums1.size();i++) {
            int top = index.top();
            index.pop();
            bool check = false;
            for (int j = top;j < nums2.size();j++) {
                if (nums2[j] > nums1[i]) {
                    hold.push_back(nums2[j]);
                    check = true;
                    break;
                }
            }
            if (!check) {
                hold.push_back(-1);
            }
        }



        return hold;
    }
};