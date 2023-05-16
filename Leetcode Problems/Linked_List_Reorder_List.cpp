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
    ListNode *newHead = NULL;
    ListNode *curr;
    ListNode *nh;
    void reorder(ListNode *head)
    {
        if (head == NULL)
        {
            return;
        }

        reorder(head->next);
        head->next = nh->next;
        nh = nh->next;
        curr->next = head;
        // cout<<nh->val;
        curr = nh;
    }

    void reorderList(ListNode *head)
    {
        newHead = head;
        curr = head;
        nh = head;
        if (head->next == NULL)
        {
            return;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << slow->val;
        ListNode *temp = slow->next;

        slow->next = NULL;
        reorder(temp);
        // curr->next=NULL;
        // return newHead;
    }
};