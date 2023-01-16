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
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *ans = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return ans;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int m = k;
        ListNode *temp = head;

        while (m > 1)
        {
            temp = temp->next;
            m--;
        }
        ListNode *tail = temp->next;
        temp->next = NULL;
        temp = tail;
        head = reverse(head);
        ListNode *traverse = head;
        while (traverse->next != NULL)
        {
            traverse = traverse->next;
        }

        m = k;

        while (temp != NULL)
        {
            if (m == 1)
            {
                ListNode *reserve = temp->next;
                ListNode *get = tail;
                temp->next = NULL;
                traverse->next = reverse(tail);
                traverse = tail;
                tail = reserve;
                m = k;
                temp = reserve;
                continue;
            }
            m--;
            temp = temp->next;
        }
        traverse->next = tail;
        return head;
    }
};





