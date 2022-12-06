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
    ListNode *oddEvenList(ListNode *head)
    {
        int count = 3;
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *head2 = head->next;
        ListNode *temp1 = head2;
        ListNode *temp = head->next->next;
        ListNode *temp2 = head;
        while (temp != NULL)
        {
            if (count % 2 == 0)
            {
                temp1->next = temp;
                temp1 = temp;
            }
            else
            {
                temp2->next = temp;
                temp2 = temp;
            }
            temp = temp->next;
            count++;
        }
        temp1->next = NULL;
        temp2->next = head2;
        return head;
    }
};