class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>hold;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        if (nums1.size() < nums2.size()) {
            for (int i = 0;i < nums1.size();i++) {
                for (int j = 0;j < nums2.size();j++) {
                    if (nums1[i] == nums2[j]) {
                        if (hold.size() == 0 || nums1[i] != hold[hold.size() - 1]) {

                            hold.push_back(nums1[i]);
                        }
                        nums2[j] = -1;
                    }
                    if (nums2[j] > nums1[i]) {
                        break;
                    }
                }
            }
        }
        else {
            for (int i = 0;i < nums2.size();i++) {
                for (int j = 0;j < nums1.size();j++) {
                    if (nums2[i] == nums1[j]) {
                        if (hold.size() == 0 || nums2[i] != hold[hold.size() - 1]) {

                            hold.push_back(nums2[i]);
                        }
                        nums1[j] = -1;
                    }
                    if (nums1[j] > nums2[i]) {
                        break;
                    }
                }
            }
        }
        return hold;
    }
};