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
        if (head->next == NULL)
        {
            return head;
        }

        ListNode *ans = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return ans;
    }
    ListNode *manage(ListNode *head, int count, int k)
    {
        if (k == 0 || head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        ListNode *prev = NULL;
        int d = count - k;
        if (d == 0)
        {
            return reverse(head);
        }
        while (d--)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        ListNode *head1 = reverse(head);
        ListNode *head2 = reverse(temp);
        temp = head1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head2;
        return reverse(head1);
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k == 0 || head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        if (count == k)
        {
            return head;
        }
        else if (k > count)
        {
            return manage(head, count, k % count);
        }
        else
        {
            return manage(head, count, k);
        }
        return head;
    }
};