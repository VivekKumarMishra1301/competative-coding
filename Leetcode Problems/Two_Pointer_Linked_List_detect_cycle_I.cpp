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
    bool hasCycle(ListNode *head)
    {
        ListNode *slow1 = head;
        ListNode *fast1 = head;
        if (!head)
        {
            return false;
        }
        if (head->next == NULL)
        {
            return false;
        }
        while (fast1 != NULL && fast1->next != NULL && slow1 != NULL)
        {
            slow1 = slow1->next;
            fast1 = fast1->next->next;
            if (fast1 == NULL || fast1->next == NULL || slow1 == NULL || slow1->next == NULL)
            {
                return false;
            }
            if (fast1 == slow1)
            {
                break;
            }
        }
        return true;
    }
};
