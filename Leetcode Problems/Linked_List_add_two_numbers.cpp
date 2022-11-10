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

    int i = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* temp3;
        ListNode* fhead;
        while (temp1 != NULL && temp2 != NULL) {

            int sum = temp1->val + temp2->val + carry;
            if (sum > 9) {
                sum = sum % 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum);
            if (i == 0) {
                fhead = newNode;
                temp3 = newNode;
                i = 1;
            }
            else {
                temp3->next = newNode;
                temp3 = temp3->next;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while (temp1 != NULL) {
            int sum = temp1->val + carry;
            if (sum > 9) {
                sum = sum % 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum);
            temp3->next = newNode;
            temp3 = temp3->next;
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            int sum = temp2->val + carry;
            if (sum > 9) {
                sum = sum % 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum);
            temp3->next = newNode;
            temp3 = temp3->next;
            temp2 = temp2->next;
        }
        if (carry == 1) {
            ListNode* newNode = new ListNode(1);
            temp3->next = newNode;
            temp3 = temp3->next;
        }
        return fhead;
    }
};