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
class Solution {
public:

    ListNode* mergeNodes(ListNode* head) {
        ListNode* start = head;
        ListNode* next = head->next;
        while (next != NULL) {
            if (next->val != 0) {
                start->val = start->val + next->val;
            }
            else {
                start->next = next->next;
                if (next->next != NULL) {

                    next = next->next;
                    start = start->next;

                }
            }
            next = next->next;
        }
        return head;
    }
};