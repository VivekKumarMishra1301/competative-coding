/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        ListNode *slow1 = head;
        ListNode *fast1 = head;
        if (!head)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            return NULL;
        }
        while (fast1 != NULL && fast1->next != NULL && slow1 != NULL)
        {
            slow1 = slow1->next;
            fast1 = fast1->next->next;
            if (fast1 == NULL || fast1->next == NULL || slow1 == NULL || slow1->next == NULL)
            {
                return NULL;
            }
            if (fast1 == slow1)
            {
                break;
            }
        }

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *first = head;
        if (head->next == head)
        {
            return head;
        }
        while (1)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                break;
            }
        }
        while (first != slow)
        {
            slow = slow->next;
            first = first->next;
        }
        return slow;
    }
};