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

    ListNode* reverse(ListNode* head) {
        if (head->next == NULL) {
            return head;
        }
        ListNode* ans = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return ans;


    }



    int pairSum(ListNode* head) {
        if (head->next->next == NULL) {
            return head->val + head->next->val;
        }
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        temp = head;
        int mid = count / 2;
        while (--mid) {
            temp = temp->next;
        }
        ListNode* curr = temp;
        temp = temp->next;
        curr->next = NULL;
        ListNode* newHead = reverse(temp);
        int max = 0;
        while (newHead != NULL) {
            int sum = head->val + newHead->val;
            if (sum > max) {
                max = sum;
            }
            newHead = newHead->next;
            head = head->next;

        }
        return max;
    }
};