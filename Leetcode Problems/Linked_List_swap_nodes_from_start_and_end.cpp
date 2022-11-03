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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* turtle = head;
        ListNode* hare = head;
        while (--k) {
            hare = hare->next;
        }
        ListNode* first = hare;
        while (hare->next != NULL) {
            turtle = turtle->next;
            hare = hare->next;
        }
        swap(first->val, turtle->val);
        return head;


    }

};