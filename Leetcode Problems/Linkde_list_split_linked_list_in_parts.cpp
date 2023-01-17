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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        ListNode *temp = head;
        int nodes = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            nodes++;
        }
        temp = head;
        int part = nodes / k;
        int remain = nodes % k;

        int rest = k - part - remain;
        vector<ListNode *> hold;
        while (k--)
        {
            int size = part;
            if (remain >= 1)
            {

                size += 1;
            }
            remain--;
            hold.push_back(head);
            while (size > 1)
            {
                temp = temp->next;
                size--;
            }
            if (temp)
            {

                head = temp->next;
                temp->next = NULL;
                temp = head;
            }
        }
        return hold;
    }
};