/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int numComponents(ListNode *head, vector<int> &nums)
    {
        map<int, int> mp;
        for (auto i : nums)
        {
            mp[i]++;
        }

        int cnt = 0;

        while (head != NULL)
        {
            if (mp.find(head->val) != mp.end())
            {
                cnt++;
                while (head != NULL && mp.find(head->val) != mp.end())
                {
                    head = head->next;
                }
            }
            if (head)
                head = head->next;
        }
        // cnt++;
        return cnt;
    }
};