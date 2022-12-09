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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *currhead = head->next;
        ListNode *next = currhead->next;
        head->next->next = head;
        head->next = next;
        ListNode *prev = head;
        head = currhead;
        while (next != NULL && next->next != NULL)
        {
            ListNode *temp = next->next->next;
            prev->next = next->next;
            next->next->next = next;
            prev = next;
            next = temp;
        }
        prev->next = next;

        return head;
    }
};