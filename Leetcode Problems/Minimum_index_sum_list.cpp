#include<climits>
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string>hold;
        int min = INT_MAX;
        int minind = 0;
        for (int i = 0;i < list1.size();i++) {
            for (int j = 0;j < list2.size();j++) {
                if (list1[i] == list2[j]) {
                    if ((i + j) < min) {
                        min = i + j;
                        minind = i;
                    }
                }
            }
        }
        hold.push_back(list1[minind]);
        for (int i = minind + 1;i < list1.size();i++) {
            for (int j = 0;j < list2.size();j++) {
                if ((i + j) == min && list1[i] == list2[j]) {
                    hold.push_back(list1[i]);
                }
            }
        }
        return hold;
    }
};