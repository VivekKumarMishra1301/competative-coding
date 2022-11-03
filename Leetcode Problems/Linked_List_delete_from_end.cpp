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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* fast = head;
        int count = 0;
        while (fast != NULL) {
            fast = fast->next;
            count++;
        }
        int run = count - n;

        if (run == 0 && n != 1) {
            head = head->next;
            return head;
        }
        ListNode* temp = head;
        while (--run) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};